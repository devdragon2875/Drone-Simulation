# Drone Search and Rescue Simulation

This a compiled simulation of a drone searching and rescuing of a randomly spawned robot.

## Download Image
  
    ```bash
    docker pull simo0999/sim
    ```

## Run Simulation

    ```bash
    docker run --name=drone_sim -p 127.0.0.1:8082:8081 -d simo0999/sim
    ```
Navigate in the browser to view:

*Simulation - http://127.0.0.1:8082

*Documentation - http://127.0.0.1:8082/docs/

## Stop Simulation

    ```bash
    docker kill drone_sim
    docker rm drone_sim
    ```
   
