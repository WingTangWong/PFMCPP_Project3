/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1

 Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to reinforce the syntax habits that C++ requires.  What you create in this project will be used as the basis of Project 5 in the course.   
 
 1) write 10 user-defined types in plain-English, 
    in the comments above your UDT, write out, in plain-english, 3 things it can do, and 5 traits.
************************
    Commit after you complete this step so i can review before you proceed with the rest of the projects
    Ping me in Slack to review this step.
    Wait for me to review before proceeding with step 2.
************************


   * WingTangWong - done, added in the space below


 2) define your struct for each of your 10 types. 
    Copy your 3+5 comments into your struct body.
    comment them out.
 
 3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    give the member variables relevant data types
 
 4) make the function parameter list for those member functions use some of your User-Defined Types
    You'll write definitions in part2 for these functions
    you'll call each of these functions in part3
 
 5) make 2 of the 10 user-defined types have a nested class.  
    this nested class also needs member functions.
    this nested class is not considered one of your 10 UDTs.
 
 6) One of your 10 UDTs should only use UDTs for its member variable types.   
    No primitives allowed!
    it still needs member variables.
 
 7) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:  

//1) write out, in plain-english, 5 traits and 3 things it can do.
Car Wash   
5 properties:
    1) has vacuum cleaners
    2) has eco-friendly cleaning supplies
    3) stores the amount of water used per week.
    4) stores amount of profit made per week
    5) number of cars serviced per day

3 things it can do:
    1) wash and wax car
    2) charge customer
    3) detail the car interior
 */


/* WingTangWong's UDT(s)
  
   (1)Drive Thru Coffee Stand 
   5 properties:
      1) physical attributes (location, dimensions, color, size, orientation)
      2) open for business or not (boolean or array of times to be checked against)
      3) stores inventory of consumables 
      4) stores financial transactions
      5) stores daily business metrics
   3 things it can do:
      1) take orders
      2) produce goods for order
      3) accept payment for goods

   (2)Microwave
   5 properties:
      1) wattage
      2) plugged in or not
      3) active or not
      4) current settings
      5) time remaining
   3 things it can do:
      1) open/close door
      2) set time/power levels
      3) start/stop

   (3)Smart Power Strip
   5 properties:
      1) network address(ip address/netmask/gateway/dns)
      2) list of individual socket states (on/off) 
      3) stored history of power consumption per socket 
      4) stored history of socket state changes
      5) stored 'uptime' value
   3 things it can do:
      1) change individual socket state: on-to-off,off-to-on,toggle/bounce
      2) perform global socket change: all on, all off, all toggle/bounce
      3) reconfigure network settings

   (4)Kitchen Droid
   5 properties:
      1) Left/Right armature hardware installed: none, or one of several kitchen tool ID(s) assigned/loaded.
      2) Inventory of alternate hardware(s) swappable. 
      3) List of activities performable with arm/tools 
      4) List of ingredients in stock
      5) Menu of dishes Kitchen Droid can make
   3 things it can do:
      1) Prepare Meal From Menu
      2) Swap tools
      3) Validate menu choice with available tools, ingredients,and actions available. 

   (5)Apple Store
   5 properties:
      1) Inventory of Apple products
      2) Location
      3) Hours of operation
      4) Number of staff
      5) Hourly Profit
   3 things it can do:
      1) Sell Apple Products To New Customers
      2) Sell Apple Products To Existing Customers
      3) Collect Money

   (6)Wild Squirrel
   5 properties:
      1) Number of nuts in mouth
      2) Number of trees visited per hour
      3) Has Jumped In Baby Carriage in Lifetime (bool)
      4) Is Sprinting(bool)
      5) Is Chittering(bool)
   3 things it can do:
      1) Place Nut In Mouth
      2) Sprint to random location (inclusive of baby carriages)
      3) Chitter for random length of time.

   (7)Dungeon Master 
   5 properties:
      1) List of voices and personas capable of enacting
      2) List of various dice to roll for actions/effects
      3) List of ideas on how to manipulate the party
      4) List of documents and reference books on hand
      5) List of player penalties for being difficult *cough*blue lightning*cough*
   3 things it can do:
      1) Enact voices and personas to party
      2) Request the party "roll for initiative"
      3) Laugh maniacally

   (8)D&D Party Members
   5 properties:
      1) Player character stats/attributes(age, sex, race, armor class, pasive perception, etc)
      2) Assortment of dice for rolling for actions and effects
      3) Is a murderhobo (bool) (senselessly killing non-player-characters in game)
      4) Fearful of Dungeon Master (bool)
      5) How badly they want to kill "that partymember" (double)
   3 things it can do:
      1) Fulfill quests
      2) Listen to the dungeon master's amazing voices
      3) Roll for initiative

   (9)Self Checkout Register
   5 properties:
      1) has screen for user interface
      2) has scanner for products
      3) has scale for bagging and validation of products
      4) has payment interface
      5) has receipt printer
   3 things it can do:
      1) ring up item
      2) accept payment
      3) print receipt

   (10)Gaming Store
   5 properties:
      1) [Self Checkout Register]
      2) [Microwave]
      3) [D&D Party Members]
      4) [Dungeon Master]
      5) [Smart Power Strip]
   3 things it can do:
      1) Host Game Sessions   (for the dungeon masters and d&d players, microwave for food)
      2) Sell Gaming Supplies (dice, paper, books, self-checkout)
      3) Users can pay for power (smart power strip, self-checkout)

*/










struct CarWash //2)        
{
    //2) has vacuum cleaners
    bool hasVacuumCleaners = true; //3) member variables with relevant data types.
    //2) has eco-friendly cleaning supplies
    bool hasEcoFriendlyCleaningSupplies = true; //3) member variables with relevant data types.
    //2) stores the amount of water used per week.
    float waterUsedPerWeek = 200.f; //3) member variables with relevant data types.
    //2) stores amount of profit made per week
    float profitPerWeek = 495.95f; //3) member variables with relevant data types.
    //2) number of cars serviced per day
    int numberOfCarsServiced = 10; //3) member variables with relevant data types.
    
    //5) make 2 of the 10 user-defined types have a nested class. 
    struct Car   
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);   
    };

    /* 
    member functions with a user-defined type as the parameter.
    The user-defined type parameter happens to be the nested class.
    */

    //2) wash and wax car
    void washAndWaxCar( Car car );
    //2) charge customer
    float chargeCustomer();
    //2) detail the car interior
    void detailInterior( Car car );
    
               
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


/*
1)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
2)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
3)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
4)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
5)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
6)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
7)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
8)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
9)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
10)
5 properties:
 These 5 properties should be UDTs that you defined above.
 this goes along with the instruction:
    One of your 10 UDTs should only use UDTs for its member variable types.
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
