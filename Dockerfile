FROM alpine:3.19

WORKDIR /app

RUN apk --no-cache add ffmpeg cmake make g++ python3

COPY docker/requirements/requirements.txt requirements.txt
COPY src/ server

RUN python3 -m venv /venv
RUN /venv/bin/pip install --no-cache-dir -r requirements.txt

RUN cd server && cmake . && make

ENTRYPOINT ["/app/server/build/YT-Cut-Server"]
