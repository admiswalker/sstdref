#!/bin/sh
docker run --rm -it --name run_sstdref -v $PWD:/home -w /home -p 8000:8000 sstdref_gen:latest sh
