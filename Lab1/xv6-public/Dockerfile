FROM alpine:3.14
WORKDIR /app
RUN apk add --no-cache build-base gdb qemu-system-x86_64 gcc
COPY . /app
RUN make qemu-nox
CMD ["make", "qemu-nox"]
