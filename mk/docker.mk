# Containerized compile/run/test, using the exact same targets and problem
# resolution (ABS) as native mode - just executed inside a pinned toolchain
# image instead of your local g++-15. Works from any tier (root, section,
# leaf) since the target problem is resolved on the host first, then handed
# to the container as a root-relative P=.
#
#   make image          build/refresh the local toolchain image
#   make docker-test     compile + test/edit/run.. e.g. docker-run, docker-build, docker-clean
#
# The image is only ever built locally (`make image`); nothing is published.

DOCKER_IMAGE := cp-cpp:local
DOCKERFILE   := $(ROOT)/Dockerfile

# attach a tty only if we actually have one, so this also works unattended
TTY_FLAGS := $(shell [ -t 0 ] && echo -it || echo -i)

.PHONY: image docker-%

image: ## Build/refresh the local toolchain image (cp-cpp:local)
	docker build -t $(DOCKER_IMAGE) -f "$(DOCKERFILE)" "$(ROOT)"

docker-%: ## Run any target inside the container: make docker-test / docker-run / docker-build
	@test -n "$(ABS)" || { echo "No problem resolved. Pass P=<path>, or cd into a problem dir."; exit 1; }
	@docker image inspect $(DOCKER_IMAGE) >/dev/null 2>&1 || $(MAKE) --no-print-directory image
	docker run --rm $(TTY_FLAGS) \
	  -v "$(ROOT):/work" -w /work \
	  --user "$$(id -u):$$(id -g)" \
	  $(DOCKER_IMAGE) \
	  make $* P=$(patsubst $(ROOT)/%,%,$(ABS)) CXX=g++
