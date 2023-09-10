#!/bin/sh
docker run --rm -u $(id -u $USER) -it --name run_sstdref -v $PWD:/home -w /home -p 8000:8000 sstdref_gen:latest sh
