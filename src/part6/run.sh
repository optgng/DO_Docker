#!/bin/bash

service nginx start
nginx -s reload
./fcgi.app