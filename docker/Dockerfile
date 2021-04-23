FROM python:3.8.2-alpine

COPY requirements.txt .

RUN set -ex \
  && apk add --no-cache \
    gcc \
    g++ \
    make

RUN set -ex \
  && pip install -r requirements.txt