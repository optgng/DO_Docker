FROM debian

USER root

LABEL desc="This is a container with NGINX and web-server on C FCGI"

RUN apt-get update && apt-get install -y \
     gcc \
     spawn-fcgi \
     libfcgi-dev \
     nginx \
    && rm -rf /var/lib/apt/lists

COPY ./server/nginx.conf ./etc/nginx/nginx.conf
COPY ./server/site.c ./home/site.c
COPY ./server/run.sh ./home/run.sh

WORKDIR /home

RUN chmod u-s /usr/bin/mount \
    && chmod g-s /usr/bin/chage \
    && chmod u-s /usr/bin/newgrp \
    && chmod u-s /usr/bin/su \
    && chmod g-s /usr/bin/expiry \
    && chmod u-s /usr/bin/passwd \
    && chmod u-s /usr/bin/chsh \
    && chmod u-s /usr/bin/umount \
    && chmod u-s /usr/bin/gpasswd \
    && chmod g-s /usr/bin/wall \
    && chmod u-s /usr/bin/chfn \
    && chmod g-s /usr/sbin/unix_chkpwd \
    && gcc -Wall -Wextra -Werror site.c -lfcgi -o fcgi.app \
    && useradd nginx \
    && chown -R nginx:nginx /etc/nginx/nginx.conf \
    && chown -R nginx:nginx /home \
    && touch /var/run/nginx.pid \
    && chown -R nginx:nginx /var/run/nginx.pid \
    && rm -rf /var/log/nginx \
    && mkdir /var/log/nginx \
    && touch /var/log/nginx/error.log \
    && chown -R nginx:nginx /var/log/nginx

USER nginx

CMD ["sh", "./run.sh"]

HEALTHCHECK  --interval=30s --timeout=15s CMD curl --fail http://localhost:80/ || exit 1