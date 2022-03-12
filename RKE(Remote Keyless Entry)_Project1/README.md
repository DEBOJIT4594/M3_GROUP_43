**REMOTE KEYLESS ENTRY** 
====================

**INTRODUCTION**
--
Remote keyless entry is a system which allows users to lock and unlock the doors of the vehicle from a distance remotely. Almost 70% to 80% of the vehicles in the world comes with remote keyless entry. It requires a user to press a button on a physical fob which will send/transmit a radio signal to the receiver and locks the door. It has LEDs which will tell us that what functionality currently performing. It provides high secuirity for vehicles. Additionally it has a functionality to activate alarm or deactivate alarm and approach light.  

**FEATURES**
--

1) Use to lock or unlock vehicles from  a distance.
2) Have LEDs to indicate which functionality is currently performing.
3) Small in size and handy too.
4) Can activate/deactivate alarm of the vehicle
5) Have approach light functionality.
6) Keeps the vehicle secure.

**REQUIREMENTS**
--

**HIGH LEVEL REQUIREMENT**

|Test ID  |    Description  |  
-------------|-----------------------------------
|HL01     |    The system shall have alarm activation/deactivation functionality | 
|HL02     |    The system shall have approach light funtionality       |
|HL03     |    The system shall be secure   |
|HL04     |    The system shall lock vehicle doors wirelessly  |
|HL05     |    The system shall unlock vehicle doors wirelessly |

**LOW LEVEL REQUIREMENT**

|For High level requirement|Test ID| Description                                                     | 
---------------------------|-------|------------------------------------------------------------------
|HL04                      |LL01   | All the LEDs shall turn on at the same time by single press     |
|HL05                      |LL02   | All the LEDs shall turn off at the same time by two presses     |
|HL01                      |LL03   | All LEDs shall turn on in clockwise manner by three presses     |
|HL02                      |LL04   | All LEDs shall turn on in anti-clockwise manner by four presses |

**SWOT ANALYSIS**
--



![Screenshot (223)](https://user-images.githubusercontent.com/99093515/158006576-83df36cd-b496-4aee-9c9d-5c76b0b22f24.png)


**5W's & 1H**
--

**WHO**

- People who have vehicle. 
 
**WHAT**
 
- It is a system which wirelessly lock/unlock door of a vehicle and perform different functionalities from a distance.
 
**WHEN**
 
- Whenever the user wants to lock or unlock the door of the vehicle and wants to use its other features.
 
 **WHERE**
 
 - It can be use anywhere

**WHY**

- For an easy use of vehicle and to ensure secuirity.

**HOW**

- The system can be operated by just clicking a button .

**ARCHITECTURE**
--
**BEHAVIOURAL DIAGRAM**

![M3_FLOWCHAT](https://user-images.githubusercontent.com/98827063/157807800-fe91f304-c0bd-4f5d-9d4f-80b07c78daee.jpg)



**STRUCTURAL DIAGRAM**

![M3_STRUCTURAL](https://user-images.githubusercontent.com/98827063/157811589-a95b4b59-e077-456e-8e43-3ef75b26a0c3.jpg)



**BLOCK DIAGRAM**

![WhatsApp Image 2022-03-11 at 16 42 57](https://user-images.githubusercontent.com/98827063/157934025-405fe9fc-67d3-4f5b-ae42-313ea34c263b.jpeg)



**TEST PLANS**
---

**HIGH LEVEL TEST PLAN**
======

|Test ID  |Description                        | Input             |Expected Output         |Actual Output          |Pass/Fail |
--------------------                          |---------------    |------------------      |---------------        |----------|-----------
|   01    | Vehicle door lock                 | 1 press button    | Vehicle locked         | Vehicle locked        | Pass     |
|   02    | Vehicle door unlock               | 2 press buttons   | Vehicle unlocked       | Vehicle unlocked      | Pass     |
|   03    | Alarm activation/deactivation     | 3 press buttons   | Activated/deactivated  | Activated/deactivated | Pass     |
|   04    | Approach light                    | 4 press buttons   | On                     | On                    | Pass     |


**LOW LEVEL TEST PLAN** 
====

|Test ID  |Description                                  | Input            |Expected Output                       |Actual Output                         |Pass/Fail |
--------------------                                    |---------------   |------------------                    |---------------                       |--------- |-
|   01    | All LEDs shall on at same time              | 1 press button   | All LEDs on                          | All LEDs on                          | Pass     |
|   02    | All LEDs shall off at same time             | 2 press buttons  | All LEDs off                         | All LEDs off                         | Pass     |
|   03    | All LEDs shall on in clockwise              | 3 press buttons  | All LEDs on in clockwise manner      | All LEDs on in clockwise manner      | Pass     |
|   04    | All LEDs shall on in anti-clockwise         | 4 press buttons  | All LEDs on in anti-clockwise manner | All LEDs on in anti-clockwise manner | Pass     |
