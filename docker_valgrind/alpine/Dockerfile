# FROM alpine:latest
FROM quay.io/school21/alpine:3.16

RUN apk update && \
    apk add --no-cache valgrind g++ make cmake git libstdc++ libgcc

RUN mkdir -p /usr/src/gtest && \
    git clone https://github.com/google/googletest.git /usr/src/gtest && \
    cd /usr/src/gtest && \
    cmake -Bbuild -H. && \
    cmake --build build

RUN cp -r /usr/src/gtest/googletest/include/gtest /usr/include

RUN cp /usr/src/gtest/build/lib/*.a /usr/lib

WORKDIR /usr/src/

COPY ./src /usr/src/
COPY ./src/docker_valgrind/start.sh /usr/src/

ENTRYPOINT ["/bin/sh", "start.sh"]
