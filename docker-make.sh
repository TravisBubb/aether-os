#!/bin/bash

set -e

docker compose run --rm aetheros-build make "$@"
