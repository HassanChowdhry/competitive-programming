# Toolchain container matching the local dev setup (Homebrew GCC 15.2.0, -std=c++17).
# bits/stdc++.h and friends ship with the official gcc image's libstdc++-dev - no
# custom compiler build needed. make+git are added so the container can run the
# exact same Makefile targets as the host (see mk/docker.mk).
#
# Built by `make image`, used by `make docker-test` / `docker-run` / `docker-build`.
FROM gcc:15-bookworm

RUN apt-get update \
    && apt-get install -y --no-install-recommends make git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /work
