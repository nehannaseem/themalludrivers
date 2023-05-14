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

Using an Arduino board, you can build a self-driving car that can sense its environment, make decisions, and drive on its own. The car can be equipped with a range of cameras such as  2 that can detect obstacles and other objects in its path. It can also use machine learning algorithms to analyze and process data from these camera to make intelligent decisions.

In this documentation, we will provide a step-by-step guide on how to build a self-driving car using Arduino. We will cover everything from selecting the right components to assembling and programming the car. Whether you're a beginner or an experienced electronics enthusiast, this guide will help you build your very own self-driving car using Arduino.

## Design
 When discussing about the design and the components used to create vehicles, it is important to consider the specific parts and tools that are involved. In the case of our project, we have used several components, including:

1. Camera - PIXY 2 Camera: The camera is an essential component for any autonomous vehicle project as it allows the vehicle to see its environment and make informed decisions about navigation. The PIXY 2 camera is a popular choice due to its high resolution and ease of integration with other systems.


![pixy2_in_hand-300px](https://user-images.githubusercontent.com/129651787/236665844-784d054e-7ab8-4b3b-a66a-d9c4917aaff3.jpg)


2. Ultrasonic Sensor HC SRO4 Adafruit: The ultrasonic sensor is another essential component for autonomous vehicles. It provides distance measurements, enabling the vehicle to navigate its environment safely and avoid obstacles. The HC SRO4 Adafruit is a reliable and affordable sensor that is easy to use with Arduino boards.

![adafruit_products_HC-SR04_top](https://user-images.githubusercontent.com/129651787/236665944-1309cafb-f96a-4b9a-90a8-3d822e3b9ca4.jpg)


3. Arduino UNO : Arduino is a popular open-source platform for building electronic projects, and it is widely used in robotics and automation projects. The Arduino board provides a microcontroller that can interface with sensors and other components and run software programs to control the vehicle.

![71X9XbfwDKL _AC_UF1000,1000_QL80_](https://user-images.githubusercontent.com/129651787/236666012-0ad6f567-fde3-491e-82da-f4980a81dff1.jpg)

4. Wheels: Wheels are necessary for any vehicle project, and the choice of wheels depends on factors such as the vehicle's weight, the terrain it will be used on, and the desired speed and maneuverability.

![47475105122_a60c6a8175_b](https://user-images.githubusercontent.com/129651787/236666047-904168d1-872f-40e3-bff1-ff0099390d9f.jpg)

5. Lithium Ion Battery : Lithium-ion batteries, or Li-ion batteries, are a popular choice for many applications, including robotics and other electronic devices. Li-ion batteries offer several advantages over other types of batteries, such as:

* High Energy Density: Li-ion batteries have a high energy density, which means they can store a lot of energy in a small package. This is important for robotics applications, where you want to maximize the power available while minimizing the size and weight of the battery.
* Low Self-Discharge Rate: Li-ion batteries have a low self-discharge rate, which means they can retain their charge for long periods of time without needing to be recharged. This is useful for applications where the robot may need to sit idle for extended periods of time.
* Long Lifespan: Li-ion batteries have a long lifespan, which means they can be recharged hundreds or even thousands of times before needing to be replaced. This is important for robotics applications, where you want to minimize the need for battery replacements.
* Fast Charging: Li-ion batteries can be charged relatively quickly compared to other types of batteries. This is useful for applications where the robot needs to be up and running quickly after being recharged.
* Lightweight: Li-ion batteries are lightweight compared to other types of batteries, which is important for robotics applications where the weight of the battery can impact the mobility and performance of the robot.

![Keeppower-17500-3-6V-3-7V-1200mAh-Lithium-Ionen-Akku](https://user-images.githubusercontent.com/129651787/236666101-9241a73a-0777-485a-9f93-a3e4b6cc33af.jpg)

6. L298N Motor driver (Arduino): The L298N motor driver allows the Arduino board to control the vehicle's DC motor, enabling it to move forward, backward, and turn.

![71sTb-GvaLL _AC_UF1000,1000_QL80_](https://user-images.githubusercontent.com/129651787/236666193-b05c07e9-77aa-4251-bb6a-f1c77c864ab4.jpg)

7. LEGO Medium DC Motor: The LEGO Medium DC Motor is a powerful and versatile motor used in various LEGO robotics kits and projects. It is capable of running at speeds up to 250 RPM and provides a maximum torque of 40 Ncm (Newton centimeters). The motor can be controlled using a LEGO motor controller or with an Arduino.

One of the key features of the LEGO Medium DC Motor is its compact and lightweight design, which makes it ideal for use in mobile robotics applications. It has a simple interface that allows it to be easily integrated with other LEGO components, such as gears and axles, to create complex mechanisms and machines.

![image](https://user-images.githubusercontent.com/129651787/236666360-6a0d4d4c-ddcf-4ed6-b364-74dcd66b7986.jpeg)

8. MG90 Servo motor: The servo motor is a type of motor that can be controlled precisely, making it suitable for steering and other precise movements.

In the case of our project, it is likely that we chose to use axle connectors to attach wheels or other rotating components to the MG90 servo motors because of their ease of use and compatibility with other components. Additionally, axle connectors can provide additional stability and precision to the movement of your robot, making it more reliable and accurate in its movements.

![mg90s-micro-servo-motor-1690-65-B](https://user-images.githubusercontent.com/129651787/236666391-04fab203-a6a4-4a0b-81ed-468df6897f5c.jpg)

Incorporating all of these components into the design of the vehicle requires careful consideration of factors such as weight, balance, and power consumption. By selecting and implementing these parts effectively, it is possible to create a well-functioning vehicle that can navigate its environment with precision and efficiency. By discussing these components and their functions, it is possible to provide students, enthusiasts, and professionals with a better understanding of how mobility management works in practice.

9. Breadboard: A breadboard is a prototyping tool used for building and testing electronic circuits without the need for soldering. It is essentially a board with a grid of holes that allow you to insert and connect electronic components and wires together in a temporary and non-permanent manner.

The board is designed to have a common ground and power bus that runs along its length, and the holes are typically arranged in rows and columns that align with the pins on common electronic components such as resistors, capacitors, and integrated circuits (ICs). This allows you to easily plug in and connect components to create circuits without the need for a permanent connection

![9524f3be82271b9662dddab18740eabc-hi](https://user-images.githubusercontent.com/129651787/236668689-89c38240-44d8-48ff-89ab-d897c2ed2a91.jpg)

We have used LEGO because LEGO is a popular platform for robotics projects, particularly for educational and hobbyist applications. There are several reasons why we have chosen LEGO Mindstorms for your project:

* Accessibility: LEGO is widely available and relatively affordable compared to other robotics platforms. It is also easy to use, making it an ideal platform for beginners who are just starting to learn about robotics.

* Familiarity: Many people are familiar with LEGO building blocks from their childhood, which can make it easier to understand and work with the platform. Additionally, the platform is based on the LEGO Technic building system, which allows for complex and sophisticated mechanical designs.

* Compatibility: The LEGO platform is compatible with a wide range of sensors, motors, and other components, allowing for a great deal of flexibility in designing and building projects.

* Community: The LEGO community is large and active, with many resources available for learning and sharing ideas. This can be a valuable source of support and inspiration when working on a robotics project.

* Education: LEGO is often used in educational settings to teach students about robotics, programming, and engineering. The platform provides a hands-on, interactive way to learn about these topics, making it an effective tool for engaging students and promoting STEM education.

Overall, the LEGO platform is a versatile and accessible platform for robotics projects, making it a popular choice for hobbyists, students, and educators alike.

The vehicle is a custom-designed robot with the ability to navigate an obstacle course using a combination of sensors and motors. The robot consists of a 3D-printed chassis that houses an Arduino and a breadboard in the center. The robot also has three ultrasonic sensors, one in the front and two on each side, and a PIXY2 camera mounted on top of the chassis. The robot uses a combination of the sensors and camera to detect obstacles and navigate the course. The robot is powered by a Lithium-ion battery with a step-down module for regulating voltage. The robot has two motors, a Lego medium motor at the back with a differential gear. Differential gear is used to allow the wheels to rotate at different speeds while still transmitting torque to both wheels. This is particularly useful for vehicles that turn or maneuver in tight spaces, as it allows the wheels on the outside of a turn to rotate faster than the wheels on the inside.  The DC motor is connected to the rear wheels with the help of a motor driver and the motor driver helps in controling the speed. The axle connector is used to connect the servo motor to the front wheels. These components work together to allow the vehicle to detect obstacles, navigate through them, and complete the obstacle course. We have used the Ackermann steering system it is a type of steering mechanism commonly used in vehicles, which is designed to provide better turning radius and improved steering geometry. It works by having the front wheels turn at different angles during a turn, allowing for the inside wheel to turn at a sharper angle than the outside wheel. This helps reduce tire scrub and improves the overall stability and handling of the vehicle. In this project, the Ackermann steering system is implemented using a servo motor and an axle connector to rotate the front wheels at different angles.


Adding on our robotics project involves several engineering principles such as speed, torque, and power, which are critical to ensuring the proper function and performance of the robot.

* Speed is a measure of how fast your robot can move, and it is determined by the speed of the motors driving the wheels. In this project, we have selected LEGO Medium DC motors, the speed of a LEGO Medium DC Motor can vary depending on the voltage applied and the load on the motor. At its maximum rated voltage of 9 volts, the motor has a no-load speed of approximately 380 revolutions per minute (RPM). However, this speed can be reduced when the motor is under load or when a lower voltage is applied. The speed of the motor can also be controlled using a motor controller or by adjusting the input voltage. The speed of the robot will depend on the gearing and wheel size used in the design, as well as other factors such as friction and weight.

* Torque is a measure of the twisting force produced by the motor, and it is essential for driving the robot's wheels. The torque of your motors determines how much force they can exert on the wheels, which in turn affects the robot's ability to move and carry loads. In our project, we have selected step-down module, which can regulate the voltage and current flowing to the motors, ensuring that they receive a consistent supply of power.

* Power is a measure of the rate at which energy is transferred, and it is essential for driving the motors and other components of your robot. The power output of your motors determines how much work they can perform, and it is directly proportional to the product of torque and speed. In this project, we have selected the L298N motor driver, which can control the speed and direction of the motors by varying the voltage and current supplied to them.

Overall, the engineering principles of speed, torque, and power are critical to the proper function and performance of your robot. By selecting motors, drivers, and other components that are matched to the requirements of your design, you can ensure that your robot will move efficiently and accurately, while also providing the power and torque necessary to perform its intended tasks.

## 3D Printed Materials
1. Axle connector: Axle connectors are an essential part of many robotics projects, as they provide a stable and secure connection between servo motors or other motor types and rotating components such as wheels. The axle connector is responsible for transferring the torque and rotation of the motor to the wheel or other component, ensuring that it rotates smoothly and accurately in response to the motor's movement.

In our project, it appears that we have chosen to 3D print the axle connectors. There are several reasons why we choose to do this:

* Customization: 3D printing allows you to create a custom-designed axle connector that is tailored to the specific needs of your project. You can adjust the dimensions and shape of the connector to fit the size and shape of your motor's output shaft and the rotating component you are using, ensuring a perfect fit and secure connection.

* Material Selection: 3D printing gives you the flexibility to choose from a wide range of materials for your axle connector, such as plastic, metal, or composite materials. This allows you to select the material that best suits the requirements of your project, such as strength, durability, or weight.

* Cost: 3D printing can be a cost-effective way to produce a custom-designed axle connector for your project. Depending on the size and complexity of your design, 3D printing can be more affordable than other manufacturing methods, such as injection molding or CNC machining.

Overall, 3D printing the axle connectors allows you to create a custom-designed part that meets the specific needs of your project, while also providing flexibility in terms of material selection and cost. This ensures a stable and secure connection between your motor and rotating component, which is essential for the smooth and accurate movement of your robot.

2. Chasis for Ultrasonic Sensor: The chassis of the ultrasonic sensor is an important component of our robotics project as it provides a stable and secure mounting location for the sensor. The chassis is designed to hold the sensor in place and ensure that it is positioned correctly relative to other components, such as the motors and wheels.

In our project, it appears that we have chosen to 3D print the chassis for your ultrasonic sensor. There are several reasons why we choose to do this:

* Customization: 3D printing allows you to create a custom-designed chassis that is tailored to the specific needs of your project. You can adjust the dimensions and shape of the chassis to fit the size and shape of your ultrasonic sensor, and to ensure that it fits properly within the overall design of your robot.

* Material Selection: 3D printing gives you the flexibility to choose from a wide range of materials for your chassis, such as plastic, metal, or composite materials. This allows you to select the material that best suits the requirements of your project, such as strength, durability, or weight.

* Cost: 3D printing can be a cost-effective way to produce a custom-designed chassis for your ultrasonic sensor. Depending on the size and complexity of your design, 3D printing can be more affordable than other manufacturing methods, such as injection molding or CNC machining.

Overall, the chassis for your ultrasonic sensor is an essential component of your robotics project that provides a stable and secure mounting location for the sensor. By 3D printing the chassis, you can create a custom-designed part that meets the specific needs of your project, while also providing flexibility in terms of material selection and cost

3. Chassis for PIXY 2 Camera: The PIXY 2 camera is a small camera module that can be used to detect objects and colors in the environment. When using the PIXY 2 camera in a robotics project, it is important to ensure that the camera is securely mounted and protected from any potential damage during operation. This is where the need for a chassis comes in.

By 3D printing a chassis for the PIXY 2 camera, you can ensure that the camera is mounted securely in a fixed position on the robot and that it is protected from any impacts or other sources of damage during operation. The chassis can also help to keep the camera module clean and free of dust and other debris that may accumulate during use.

The design of the chassis can be customized to fit the specific requirements of the project, such as the size and shape of the robot, the placement of other sensors and components, and the overall weight and balance of the robot. The chassis can also be designed to be easily removable and replaceable, which can be useful for troubleshooting or upgrading the robot.

Overall, the 3D printed chassis for the PIXY 2 camera is an important component of the robotics project, as it helps to ensure the reliable and accurate operation of the camera module while also protecting it from potential damage during use.


## Power Source

One of the most critical aspects of any mobile robotics project is the power source. For this project, we have selected 2 LI-ion batteries with a capacity of 3.7 volt, which is capable of providing the required voltage and current to power the motors, sensors, and other components on the vehicle. To maximize battery life, we have carefully selected sensors that consume minimal power while still providing the necessary data to help the vehicle negotiate different challenges. These sensors include the PIXY 2 camera for visual recognition, the HC SRO4 ultrasonic sensor for distance measurement, and the MUGOSO gyroscope and accelerometer for motion tracking. We have also included a MG90 servo motor to actuate the camera and a step-down module to regulate voltage levels. To ensure reliable and efficient operation, we have designed a professional wiring diagram that includes all components and connections, as well as a comprehensive BOM that details each component and its specifications. With this approach, we can be confident that our vehicle will operate safely, reliably, and efficiently.

## How we overcame obstacles
To navigate the obstacle course, we have implemented a combination of vision-based navigation and ultrasonic sensing. The PIXY 2 camera provides real-time video feedback that is processed by an onboard computer running custom software developed using Aurdino programming language. The software detects and tracks obstacles in the path of the vehicle, calculates their position and size, and generates a path plan to avoid them. The HC SRO4 ultrasonic sensor is used to provide distance information and adjust the vehicle's speed accordingly. To ensure efficient and reliable operation, we have designed the software using a modular approach, with each module responsible for a specific task. We have also included comprehensive comments and documentation in the source code to aid in understanding and future development. The software is executed on an Arduino UNO microcontroller, which controls the various motors and servos that actuate the vehicle's movement and camera positioning. We have designed flow diagrams and pseudo code to aid in understanding the software logic and to facilitate debugging and modification. With this approach, we can be confident that our vehicle will effectively negotiate the obstacle course and complete the assigned tasks.

In conclution our robotics project is more than just a collection of components and parts; it is a testament to the power of imagination, creativity, and innovation. Through our hard work, determination, and ingenuity, we have transformed a simple idea into a fully functioning robot, capable of performing a wide range of tasks.

By using LEGO, 3D printing technology, and a variety of sensors and motors, we have harnessed the principles of engineering and applied them in a way that is both practical and inspiring. Our robot represents the culmination of countless hours of planning, design, and testing, as well as a deep understanding of the mechanics and physics that govern its operation.

But our project is more than just a technical achievement; it is also a reflection of our passion and commitment to making a difference in the world. Whether we are using our robot to explore new frontiers, solve complex problems, or simply bring joy and wonder to others, you are making a positive impact on the world around us.

So, as we continue to refine and improve our robot, we will never lose sight of the incredible journey that has brought us to this point. Embrace the challenges, celebrate the successes, and always remember that the most extraordinary things are often achieved by those who refuse to give up on their dreams.
