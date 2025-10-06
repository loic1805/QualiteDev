# Dockerfile pour le projet Bubble Sort
FROM gcc:latest

WORKDIR /app

COPY . .

RUN make all

CMD ["./bubble_sort"]

#commande à lancer : 
# sudo docker build -t bubblesort-c:latest . 
# sudo docker run --rm bubblesort-c:latest