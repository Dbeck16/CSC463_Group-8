Authors: Dalton Becker & Sam Selkregg
Lab: Maze with Touch Sensors
**/


int LEFT_MOTOR = 0;//controls left motor input
int RIGHT_MOTOR = 3;//controls right motor input
int sensorFront = 15;//digital input which recieves the first sensor
int sensorRight = 13;//digital input which recieves the second sensor

/*
*Method for moving the forward
*/
void forward()
{
    motor(LEFT_MOTOR, 50);
    motor(RIGHT_MOTOR, -50);
}

/*
*method for turning right
*/
void right()
{
    motor(LEFT_MOTOR, 50);
    motor(RIGHT_MOTOR, 50);
}

/*
*method for turning left
*/
void left()
{
    motor(LEFT_MOTOR, -50);
    motor(RIGHT_MOTOR, -50);
}

/*
*method for going backwards
*/
void back()
{
    motor(LEFT_MOTOR, -50);
    motor(RIGHT_MOTOR, 50);
}

/*
*method for stopping all the motors
*/
void stop()
{
    ao();
}

/*
Main function
*/
void main()
{
    while(start_button())//while start button is true
      {
        //checks if either of the sensors are touched
        if(digital(sensorFront))
          {
            //stops the robot, gets it away from the wall, and will turn left
            printf("Front sensor hit");
            stop();
            sleep(.1);
            back();
            sleep(1.0);
            left();
            sleep(2.5);
        }else if(digital(sensorRight))
          {
            //bumps the robot left if the sensor on the right goes off
            printf("Right sensor hit");
            stop();
            sleep(.1);
            back();
            sleep(.25);
            left();
            sleep(.3);
        }
           forward(); //move forward for .3 seconds before checking sensors again
           sleep(.3); 
    }
}
    
