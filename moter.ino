class Motor{
  short int enable;   //the enable pin  
  short int input1;   //the first or vcc of motor
  short int input2;   //the 2nd input or gnd of motor
  //unsigned  int PWM;
  public:
  Motor(short int enablePinNo,short int input1PinNo,short int input2PinNo){ //constructor
     enable = enablePinNo;
     input1 = input1PinNo;
     input2 = input2PinNo;
     }
  void Setup(){   //Goes in the setup function
    pinMode(enable, OUTPUT);
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
  }
  void forward(unsigned int PWM){   //moves the bot forward
    analogWrite(enable, PWM);
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
  }
  void backward(unsigned int PWM){  /*moves the bot in reverse useful for hardBrake*/
    analogWrite(enable, PWM);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
  }
  void brake(unsigned long PWM){    /*stops the bot PWM given if you want to keep any minimum bare value*/
    analogWrite(enable, PWM);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
  }
};

Motor backRightMotor(brme,brmi1,brmi2);
Motor backLeftMotor(blme,blmi1,blmi2);
