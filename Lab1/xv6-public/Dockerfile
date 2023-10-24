FROM alpine:3
WORKDIR /app
RUN apk add --no-cache build-base gdb qemu-system-x86_64 gcc
COPY . /app
RUN make
RUN make qemu
CMD ["make", "qemu"]
