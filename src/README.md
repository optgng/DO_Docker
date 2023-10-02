# Simple Docker

Введение в докер. Разработка простого докер образа для собственного сервера.

## Part 1. Готовый докер

### Выкачиваю образ `nginx`

  ``` shell
  docker pull nginx
  ```

  ![task_1](images/task_1_1.png)  

### Проверяю наличие образа

  ``` shell
  docker images
  ```

  ![task_1](images/task_1_3.png)  

### Запукаю образ в тихом режиме

  ``` shell
  docker run -d --name enginx nginx
  ```

  ![task_1](images/task_1_3.png)  

### Проверяю, что образ запустился

  ``` shell
  docker ps
  ```

  ![task_1](images/task_1_4.png)  

### По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

### Размер контейнера в байтах

  ``` shell
  docker inspect --size enginx | grep -i size
  ```

  ![task_1](images/task_1_5.png)  

### Порты контейнера

  ``` shell
  docker inspect enginx | grep -i ports -A 1
  ```

  ![task_1](images/task_1_6.png)  

### ip-адрес контейнера

  ``` shell
  docker inspect enginx | grep -i ipaddress
  ```

  ![task_1](images/task_1_7.png)  

### Остановил контейнер

  ``` shell
  docker stop enginx
  ```

  ![task_1](images/task_1_8.png)  

### Контейнер действительно остановился

  ![task_1](images/task_1_9.png)  
***

### Запустил контейнер с портами 80 и 443

  ``` shell
  docker run --name enginxxx -d -p 80:80 -p 443:443 nginx
  ```

  ![task_1](images/task_1_10.png)  

### Cтартовая страница `nginx` доступна

  ![task_1](images/task_1_11.png)  

### Перезапустил докер контейнер

  ``` shell
  docker restart enginxxx
  ```

  ![task_1](images/task_1_12.png)  

### Контейнер запустился и работает

  ![task_1](images/task_1_13.png)  

## Part 2. Операции с контейнером

### Содержимое файла `nginx.conf`

  ``` shell
  docker exec enginxxx cat /etc/nginx/nginx.conf
  ```

  ![task_2](images/task_2_1.png)  

### Настроил конфигурационный файл `nginx`

  ![task_2](images/task_2_2.png)  

### Скопировал файл `nginx.conf` внутрь docker-контейнера c помощью команды

  ```shell
    docker cp /etc/nginx/nginx.conf enginxxx:/etc/nginx/
  ```

  ![task_2](images/task_2_3.png)  

### Перезапустил `nginx` внутри докер образа через команды

  ```shell
    docker exec enginxxx nginx -t
    docker exec enginxxx nginx -s reload
  ```

  ![task_2](images/task_2_4.png)

### Страничка статус работает

  ![task_2](images/task_2_5.png)

### Экспортировал контейнер в файл `container.tar` с помощью команды

  ```shell
    docker export -o container.tar enginxxx
  ```

  ![task_2](images/task_2_6.png)

### Остановил контейнер enginxxx

  ![task_2](images/task_2_7.png)

### Удалил образ `nginx`

  ```shell
    docker rmi -f nginx
  ```

  ![task_2](images/task_2_8.png)

### Удалил остановленный контейнер

  ![task_2](images/task_2_9.png)

### Импортировать контейнер обратно с помошью команды

  ```shell
    sudo docker import -c 'CMD ["nginx", "-g", "daemon off;"]' container.tar new_nginx:latest
  ```

  ![task_2](images/task_2_10.png)

### Запустил импортированный контейнер

  ![task_2](images/task_2_11.png)

### Страничка статуса доступна

  ![task_2](images/task_2_12.png)

## Part 3. Мини веб-сервер

### Написал программку на `C` и `FCGI`

  ![task_3](images/task_3_1.png)

### Так как используется библиотека `fcgiapp.h`, то потребовался запуск только бинарного файла, не через `spawn-fcgi`. Файл был запущен в фоновом режиме

  ![task_3](images/task_3_2.png)

### Содержимое `nginx.conf`

  ![task_3](images/task_3_3.png)

### В браузере отображается написанная страничка

  ![task_3](images/task_3_4.png)

## Part 4. Свой докер

### Содержимое `Dockerfile`

  ![task_4](images/task_4_1.png)

### Собираю `Dockerfile` с помощью команды

  ```shell
    docker build -t fcgi_c:v1.0 . -f Dockerfile 
  ```

  ![task_4](images/task_4_2.png)

### Образ собрался корректно, добавился в список

  ![task_4](images/task_4_3.png)

### Запустил контейнер с помощью команды

  ```shell
  docker run --name teod -d -p 443:81 -p 80:81 -v /home/teod/nginx/nginx.conf:/etc/nginx/nginx.conf fcgi_c:v1.0
  ```

  ![task_4](images/task_4_4.png)

### Страничка по адресу `localhost:80` доступна

  ![task_4](images/task_4_5.png)

### Страничка по адресу `localhost:80/status` доступна

  ![task_4](images/task_4_6.png)

## Part 5. **Dockle**

### Созданный ранее докер образ был просканирован, `Dockle` выдал следующие ошибки

  ![task_5](images/task_5_1.png)

### Все ошибки были исправлены

  ![task_5](images/task_5_2.png)

### Однако, поменялся и `Dockerfile`

  ![task_5](images/task_5_3.png)

## Part 6. Базовый `Docker Compose`

### Содержимое файла `docker-compose.yaml`

  ![task_6](images/task_6_1.png)

### Cодержимое файла `nginx.conf` для контейнера server

  ![task_6](images/task_6_2.png)

### Cодержимое файла `nginx.conf` для контейнера app

  ![task_6](images/task_6_3.png)

### Собираю и поднимаю контейнеры с помощью команд

```shell
  docker-compose build
  docker-compose up -d
```

  ![task_6](images/task_6_4.png)

### Страничка по адресу `localhost:80` работает

  ![task_6](images/task_6_5.png)
