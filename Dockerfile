
FROM gcc:13

WORKDIR /app

COPY . .

RUN mkdir build && cd build &&     cmake .. &&     cmake --build . --config Release

CMD ["./build/task_scheduler"]
