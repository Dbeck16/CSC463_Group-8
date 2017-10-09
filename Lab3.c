/**
Authors: Dalton Becker & Sam Selkregg
Lab: Line Following
**/


int LEFT_MOTOR = 0;//controls left motor input
int RIGHT_MOTOR = 3;//controls right motor input
int sensorL;//keeps track of what the sensor is reading
int sensorR;
int leftTurn = 0;//keeps track of how long it should spend turning
int rightTurn = 0;//keeps track of how long it should spend turning
int pow;
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

void fuzzyLeft()
{
	motor(LEFT_MOTOR, pow/2);
	motor(RIGHT_MOTOR, - 50);
}
void fuzzyRight()
{
	motor(LEFT_MOTOR, 50)
	motor(RIGHT_MOTOR, -pow/2);
}
/*
*checks what the sensor is reading
*/
void checkSensors()
{
    sensorL = analog(4);
	sensorR = analog(6);
}

fuzzification()
{
	if (sensorL < sensorR)
	{
		pow = sensorL/25 * 10;
		fuzzyLeft();
		sleep(.1);
	}
	else if(sensorL > sensorR)
	{
		pow = sensorR/25 * 10;
		fuzzyRight();
		sleep(.1);
	}
	else if(sensorL=sensorR)
	{
		forward();
		sleep(.1);
	}
}	


/*
Main function
*/
void main()
{
    while(start_button())//while start button is true
     {
        checkSensor();   //check sensor
		fuzzification(); 
    }
}
