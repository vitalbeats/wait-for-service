FROM alpine:3.13 AS builder
RUN apk add --no-cache gcc musl-dev
COPY main.c /
RUN gcc -static main.c -o /wait-for-service

FROM scratch AS runner
COPY --from=builder /wait-for-service /
ENTRYPOINT [ "/wait-for-service" ]