# Root control panel for the whole cses-cpp workspace. Run `make help` for commands.
#
# Three ways to use this, from three tiers:
#   - here at the root:  make new P=Codeforces/2241/A   make test P=CSES/Mathematics/Nim-Game-I
#   - inside a section (e.g. Codeforces/, CSES/): shorter paths, see that dir's Makefile
#   - inside a problem dir itself: bare `make test` / `make run` / `make edit` just work
#
# All the actual recipes live in mk/common.mk, shared by every tier.

include mk/common.mk

.DEFAULT_GOAL := help
