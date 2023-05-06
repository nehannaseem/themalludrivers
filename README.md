Engineering materials
====

This repository contains engineering materials of a self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2022.

## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members)
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom)
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements. If there is nothing to add to this location, the directory can be removed.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation how to connect to a SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions etc. If there is nothing to add to this location, the directory can be removed.

## Introduction

Self-driving cars have become a hot topic in recent years due to their potential to revolutionize transportation. These cars can navigate and operate without human input, using a combination of sensors, cameras, and sophisticated algorithms. In order to build a self-driving car, various technologies such as machine learning, computer vision, and robotics are employed.

One such technology that can be used to create a self-driving car is Arduino. Arduino is an open-source electronics platform based on easy-to-use hardware and software. It allows you to create interactive objects and projects that can sense and control the physical world.

Using an Arduino board, you can build a self-driving car that can sense its environment, make decisions, and drive on its own. The car can be equipped with a range of cameras such as pixy 2 that can detect obstacles and other objects in its path. It can also use machine learning algorithms to analyze and process data from these camera to make intelligent decisions.

In this documentation, we will provide a step-by-step guide on how to build a self-driving car using Arduino. We will cover everything from selecting the right components to assembling and programming the car. Whether you're a beginner or an experienced electronics enthusiast, this guide will help you build your very own self-driving car using Arduino.

## Design
 When discussing about the design and the components used to create vehicles, it is important to consider the specific parts and tools that are involved. In the case of our project, we have used several components, including:

Camera - PIX42 Camera: The camera is an essential component for any autonomous vehicle project as it allows the vehicle to see its environment and make informed decisions about navigation. The PIX42 camera is a popular choice due to its high resolution and ease of integration with other systems.

Ultrasonic Sensor HC SRO4 Adafruit: The ultrasonic sensor is another essential component for autonomous vehicles. It provides distance measurements, enabling the vehicle to navigate its environment safely and avoid obstacles. The HC SRO4 Adafruit is a reliable and affordable sensor that is easy to use with Arduino boards.

Arduino UNO or Mega: Arduino is a popular open-source platform for building electronic projects, and it is widely used in robotics and automation projects. The Arduino board provides a microcontroller that can interface with sensors and other components and run software programs to control the vehicle.

Battery: A battery is required to power the vehicle's electrical components, and the choice of battery depends on factors such as voltage, capacity, and weight. The specific battery chosen for your project may have been based on factors such as availability and compatibility with other components.

Wheels: Wheels are necessary for any vehicle project, and the choice of wheels depends on factors such as the vehicle's weight, the terrain it will be used on, and the desired speed and maneuverability.

Ball bearings: Ball bearings reduce friction and improve the efficiency of the vehicle's wheels, resulting in smoother and more reliable performance.

LM2596 - Step down module: The LM2596 is a voltage regulator that can reduce the voltage from the battery to a level suitable for powering other components in the vehicle.

LIPO battery - 2 XT60 connector: LIPO batteries are a popular choice for robotics and other electronic projects due to their high energy density and low weight. The XT60 connector is a widely used connector type that provides a secure and reliable connection between the battery and other components.

MUGOSO- gyroscope and accelerometer: The gyroscope and accelerometer provide data about the vehicle's orientation and movement, enabling the vehicle to make informed decisions about navigation and control.

Pololu 12V stepup/ down 818 V20F12: The Pololu voltage regulator provides a stable and reliable source of power for the vehicle's electrical components.

L298N motor driver (Arduino): The L298N motor driver allows the Arduino board to control the vehicle's DC motor, enabling it to move forward, backward, and turn.

12V 300 RPM DC Motor: The DC motor provides the power for the vehicle's movement, and the specific motor chosen for your project may have been based on factors such as torque, speed, and weight.

MG90 Servo motor: The servo motor is a type of motor that can be controlled precisely, making it suitable for steering and other precise movements.

Axle connector: Axle connectors are an essential part of many robotics projects, as they provide a stable and secure connection between servo motors or other motor types and rotating components such as wheels. The axle connector is responsible for transferring the torque and rotation of the motor to the wheel or other component, ensuring that it rotates smoothly and accurately in response to the motor's movement.

In our project, it appears that we have chosen to 3D print the axle connectors. There are several reasons why we choose to do this:

Customization: 3D printing allows you to create a custom-designed axle connector that is tailored to the specific needs of your project. You can adjust the dimensions and shape of the connector to fit the size and shape of your motor's output shaft and the rotating component you are using, ensuring a perfect fit and secure connection.

Material Selection: 3D printing gives you the flexibility to choose from a wide range of materials for your axle connector, such as plastic, metal, or composite materials. This allows you to select the material that best suits the requirements of your project, such as strength, durability, or weight.


Cost: 3D printing can be a cost-effective way to produce a custom-designed axle connector for your project. Depending on the size and complexity of your design, 3D printing can be more affordable than other manufacturing methods, such as injection molding or CNC machining.

Overall, 3D printing the axle connectors allows you to create a custom-designed part that meets the specific needs of your project, while also providing flexibility in terms of material selection and cost. This ensures a stable and secure connection between your motor and rotating component, which is essential for the smooth and accurate movement of your robot.

Chasis for Ultrasonic Sensor: The chassis of the ultrasonic sensor is an important component of our robotics project as it provides a stable and secure mounting location for the sensor. The chassis is designed to hold the sensor in place and ensure that it is positioned correctly relative to other components, such as the motors and wheels.

In our project, it appears that we have chosen to 3D print the chassis for your ultrasonic sensor. There are several reasons why we choose to do this:

Customization: 3D printing allows you to create a custom-designed chassis that is tailored to the specific needs of your project. You can adjust the dimensions and shape of the chassis to fit the size and shape of your ultrasonic sensor, and to ensure that it fits properly within the overall design of your robot.

Material Selection: 3D printing gives you the flexibility to choose from a wide range of materials for your chassis, such as plastic, metal, or composite materials. This allows you to select the material that best suits the requirements of your project, such as strength, durability, or weight.

Cost: 3D printing can be a cost-effective way to produce a custom-designed chassis for your ultrasonic sensor. Depending on the size and complexity of your design, 3D printing can be more affordable than other manufacturing methods, such as injection molding or CNC machining.

Overall, the chassis for your ultrasonic sensor is an essential component of your robotics project that provides a stable and secure mounting location for the sensor. By 3D printing the chassis, you can create a custom-designed part that meets the specific needs of your project, while also providing flexibility in terms of material selection and cost

In the case of our project, it is likely that we chose to use axle connectors to attach wheels or other rotating components to the MG90 servo motors because of their ease of use and compatibility with other components. Additionally, axle connectors can provide additional stability and precision to the movement of your robot, making it more reliable and accurate in its movements.

Incorporating all of these components into the design of the vehicle requires careful consideration of factors such as weight, balance, and power consumption. By selecting and implementing these parts effectively, it is possible to create a well-functioning vehicle that can navigate its environment with precision and efficiency. By discussing these components and their functions, it is possible to provide students, enthusiasts, and professionals with a better understanding of how mobility management works in practice.

We have used LEGO Mindstorms because LEGO Mindstorms is a popular platform for robotics projects, particularly for educational and hobbyist applications. There are several reasons why we have chosen LEGO Mindstorms for your project:

1. Accessibility: LEGO Mindstorms is widely available and relatively affordable compared to other robotics platforms. It is also easy to use, making it an ideal platform for beginners who are just starting to learn about robotics.

2. Familiarity: Many people are familiar with LEGO building blocks from their childhood, which can make it easier to understand and work with the Mindstorms platform. Additionally, the Mindstorms platform is based on the LEGO Technic building system, which allows for complex and sophisticated mechanical designs.

3. Compatibility: The LEGO Mindstorms platform is compatible with a wide range of sensors, motors, and other components, allowing for a great deal of flexibility in designing and building projects.

4. Community: The LEGO Mindstorms community is large and active, with many resources available for learning and sharing ideas. This can be a valuable source of support and inspiration when working on a robotics project.

5. Education: LEGO Mindstorms is often used in educational settings to teach students about robotics, programming, and engineering. The platform provides a hands-on, interactive way to learn about these topics, making it an effective tool for engaging students and promoting STEM education.

Overall, the LEGO Mindstorms platform is a versatile and accessible platform for robotics projects, making it a popular choice for hobbyists, students, and educators alike.

Adding on our robotics project involves several engineering principles such as speed, torque, and power, which are critical to ensuring the proper function and performance of the robot.

Speed is a measure of how fast your robot can move, and it is determined by the speed of the motors driving the wheels. In this project, we have selected 12V 300 RPM DC motors, which means that they rotate at a speed of 300 rotations per minute when powered by a 12V power supply. The speed of the robot will depend on the gearing and wheel size used in the design, as well as other factors such as friction and weight.

Torque is a measure of the twisting force produced by the motor, and it is essential for driving the robot's wheels. The torque of your motors determines how much force they can exert on the wheels, which in turn affects the robot's ability to move and carry loads. In our project, we have selected LM2596 step-down module, which can regulate the voltage and current flowing to the motors, ensuring that they receive a consistent supply of power.

Power is a measure of the rate at which energy is transferred, and it is essential for driving the motors and other components of your robot. The power output of your motors determines how much work they can perform, and it is directly proportional to the product of torque and speed. In this project, we have selected the L298N motor driver, which can control the speed and direction of the motors by varying the voltage and current supplied to them.

Overall, the engineering principles of speed, torque, and power are critical to the proper function and performance of your robot. By selecting motors, drivers, and other components that are matched to the requirements of your design, you can ensure that your robot will move efficiently and accurately, while also providing the power and torque necessary to perform its intended tasks.

## Power Source

One of the most critical aspects of any mobile robotics project is the power source. For this project, we have selected 2 LIPO batteries with a capacity of 3.7 volt, which is capable of providing the required voltage and current to power the motors, sensors, and other components on the vehicle. To maximize battery life, we have carefully selected sensors that consume minimal power while still providing the necessary data to help the vehicle negotiate different challenges. These sensors include the PIX42 camera for visual recognition, the HC SRO4 ultrasonic sensor for distance measurement, and the MUGOSO gyroscope and accelerometer for motion tracking. We have also included a MG90 servo motor to actuate the camera and an LM2596 step-down module to regulate voltage levels. To ensure reliable and efficient operation, we have designed a professional wiring diagram that includes all components and connections, as well as a comprehensive BOM that details each component and its specifications. With this approach, we can be confident that our vehicle will operate safely, reliably, and efficiently.

## How we overcame obstacles
To navigate the obstacle course, we have implemented a combination of vision-based navigation and ultrasonic sensing. The PIX42 camera provides real-time video feedback that is processed by an onboard computer running custom software developed using Aurdino programming language. The software detects and tracks obstacles in the path of the vehicle, calculates their position and size, and generates a path plan to avoid them. The HC SRO4 ultrasonic sensor is used to provide distance information and adjust the vehicle's speed accordingly. To ensure efficient and reliable operation, we have designed the software using a modular approach, with each module responsible for a specific task. We have also included comprehensive comments and documentation in the source code to aid in understanding and future development. The software is executed on an Arduino UNO microcontroller, which controls the various motors and servos that actuate the vehicle's movement and camera positioning. We have designed flow diagrams and pseudo code to aid in understanding the software logic and to facilitate debugging and modification. With this approach, we can be confident that our vehicle will effectively negotiate the obstacle course and complete the assigned tasks.

In conclution our robotics project is more than just a collection of components and parts; it is a testament to the power of imagination, creativity, and innovation. Through our hard work, determination, and ingenuity, we have transformed a simple idea into a fully functioning robot, capable of performing a wide range of tasks.

By using LEGO Mindstorms, 3D printing technology, and a variety of sensors and motors, we have harnessed the principles of engineering and applied them in a way that is both practical and inspiring. Our robot represents the culmination of countless hours of planning, design, and testing, as well as a deep understanding of the mechanics and physics that govern its operation.

But our project is more than just a technical achievement; it is also a reflection of our passion and commitment to making a difference in the world. Whether we are using our robot to explore new frontiers, solve complex problems, or simply bring joy and wonder to others, you are making a positive impact on the world around us.

So, as we continue to refine and improve our robot, we will never lose sight of the incredible journey that has brought us to this point. Embrace the challenges, celebrate the successes, and always remember that the most extraordinary things are often achieved by those who refuse to give up on their dreams.
