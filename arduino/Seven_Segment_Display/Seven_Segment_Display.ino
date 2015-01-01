void setup() {               
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
//  pinMode(7, OUTPUT);
}

// 4
//3 5
// 2
//0 6
// 1 7

void loop() {
  seven_segment_display(0,0,1,0,0,0,0);  // 0
  seven_segment_display(1,1,1,1,1,0,0);  // 1
  seven_segment_display(0,0,0,1,0,0,1);  // 2
  seven_segment_display(1,0,0,1,0,0,0);  // 3
  seven_segment_display(1,1,0,0,1,0,0);  // 4
  seven_segment_display(1,0,0,0,0,1,0);  // 5
  seven_segment_display(0,0,0,0,0,1,0);  // 6
  seven_segment_display(1,1,1,1,0,0,0);  // 7
  seven_segment_display(0,0,0,0,0,0,0);  // 8
  seven_segment_display(1,0,0,0,0,0,0);  // 9
}

void seven_segment_display(int in0, int in1, int in2, int in3, int in4, int in5, int in6) {
  digitalWrite(0, in0);
  digitalWrite(1, in1);
  digitalWrite(2, in2);
  digitalWrite(3, in3);
  digitalWrite(4, in4);
  digitalWrite(5, in5);
  digitalWrite(6, in6);
  delay(1000);
} 

