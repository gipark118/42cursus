#!/bin/sh

minikube delete
minikube start --driver=virtualbox
eval $(minikube docker-env)

minikube addons enable metallb
kubectl apply -f srcs/metallb/config.yaml

docker build -t ft-services-influxdb srcs/influxdb
docker build -t ft-services-mysql srcs/mysql
docker build -t ft-services-telegraf srcs/telegraf
docker build -t ft-services-nginx srcs/nginx
docker build -t ft-services-grafana srcs/grafana
docker build -t ft-services-phpmyadmin srcs/phpmyadmin
docker build -t ft-services-wordpress srcs/wordpress
docker build -t ft-services-ftps srcs/ftps

kubectl apply -f srcs/influxdb/influxdb.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/telegraf/telegraf.yaml
kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/grafana/grafana.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/ftps/ftps.yaml

minikube addons enable metrics-server
minikube addons enable dashboard

minikube dashboard
