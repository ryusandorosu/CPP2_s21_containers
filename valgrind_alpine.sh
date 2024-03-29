#!/bin/bash

#there will be "still reachable" warnings because of throws. stl behaves the same

cd ..
docker rmi -f valgrind_image
docker build . -t valgrind_image -f src/docker_valgrind/alpine/Dockerfile
docker run --rm valgrind_image
