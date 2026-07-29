# Codeforces section. From here, paths are relative to Codeforces/, e.g.:
#   make new P=2241/A       make test P=2241/A       make test   (most recent problem)

SECTION := Codeforces
include ../mk/common.mk

LETTERS ?= A B C D E

.PHONY: contest
contest: ## Scaffold a whole round at once: make contest P=2241 [LETTERS="A B C D E"]
	@test -n "$(strip $(P))" || { echo "Usage: make contest P=<contest-id> [LETTERS=\"A B C\"]"; exit 1; }
	@for L in $(LETTERS); do $(MAKE) --no-print-directory new P=$(P)/$$L OPEN=0; done
	@echo "Scaffolded Codeforces/$(P): $(LETTERS)"
	@if [ "$(OPEN)" != "0" ]; then \
	  for L in $(LETTERS); do code "$(ROOT)/$(SECTION)/$(P)/$$L/$(SRC)"; done; \
	fi
