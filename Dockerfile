
FROM gcc:13

RUN apt-get update && apt-get install -y cmake && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build &&     cmake .. &&     cmake --build .

CMD ["./build/task_scheduler"]
