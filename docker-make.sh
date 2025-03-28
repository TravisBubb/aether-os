#!/bin/bash

set -e

docker-compose build
docker compose run --rm aetheros-build make "$@"
