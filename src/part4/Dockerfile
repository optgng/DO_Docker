FROM nginx:latest

USER root

LABEL desc="This is a container \ 
            with NGINX and web-server on C FCGI"

RUN apt-get update && apt-get install -y \
     gcc \
     spawn-fcgi \
     libfcgi-dev \
    && rm -rf /var/lib/apt/lists/*

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./site.c ./teodorai/site.c

WORKDIR /teodorai/

RUN gcc -Wall -Wextra -Werror site.c -lfcgi -o fcgi.app

CMD ["nginx", "-g", "daemon off;"]