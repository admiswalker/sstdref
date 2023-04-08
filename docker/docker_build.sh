#!/bin/sh
OWN_PATH=$(dirname ${0})
cd ${OWN_PATH}

docker build -t sstdref_gen ./
