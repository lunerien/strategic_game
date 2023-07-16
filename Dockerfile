FROM ubuntu:22.04
LABEL authors="lukasz.kala"


USER root
RUN apt update && \
    apt install -y \
    cmake \
    clang \
    valgrind \
    ninja-build
COPY . /tmp
WORKDIR /tmp
ENTRYPOINT ["commmands.sh"]