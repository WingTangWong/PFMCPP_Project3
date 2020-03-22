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

// ==================================
// WingTangWong's UDT(s)
// ==================================
  
//   ==============================
//   (1)Drive Thru Coffee Stand 
struct DriveThruCoffeeStand
{
//   5 properties:
//      1) physical attributes (location, dimensions, color, size, orientation)
         double longitude   = 37.331796;
         double latitude    = -122.0296753;
         float  orientation = 180.00;
         double width  = 512.000;
         double length = 512.000;
         double height = 512.000;
         int    colorRed   = 200;
         int    colorGreen = 200;
         int    colorBlue  = 200;

//      2) open for business or not (boolean or array of times to be checked against)
         bool openForBusiness = true;

//      3) stores inventory of consumables 
         struct inventoryItem
         {
            char name[255];
            int  numberInStock;
            int  numberOnOrder;
            float pricePerItem;
            float itemWeight;
            bool perishable;
         };

         inventoryItem storeInventory[32768]; // would we ever need more than 32767 different items?


         struct menuItem
         {
            char name[255];
            int requiredIngredient; // this would be an inventory item ID number
         };

         menuItem availableProducts[32768]; // that's a huge menu... actually, multiple entries for the same item for multi-ingredient
                                            // recipes. 


//      4) stores financial transactions
         struct individualSale
         {
            int timeOfSale;
            int transactionID;
            int itemID;
            bool refunded;
         };

         individualSale financialTransactions[32768]; // I'm sure this will be fine....

//      5) stores daily business metrics

         struct dailyMetric
         {
            float grossSales;
            float netProfits;
            float totalRefunded;
         };

         dailyMetric businessLog[3699]; // "10 years" of logs with padding... lol

//   3 things it can do:
//      1) take orders
         bool takeOrder( menuItem orderItem ); // returns false if the order is invalid, true if the order is valid

//      2) produce goods for order
         bool createProductAndUpdateInventory( menuItem orderItem ); 
//      3) accept payment for goods
         bool processPayment( individualSale tx, dailyMetric log );
         
//
};
//   ==============================
//   (2)Microwave
struct Microwave
{
//   5 properties:
//      1) wattage
         float wattage;

//      2) plugged in or not
         bool powerAvailable;
//      3) active or not
         bool active;

//      4) current settings
         int powerLevel;

//      5) time remaining
         float remainingTime;



//   3 things it can do:
//      1) open/close door
         void doorChangeState( bool openDoor );         

//      2) set time/power levels
         void setPowerLevel( int newPowerLevel );
         void setTimer( int newTimeRemaining );

//      3) start/stop
         void startMicrowave();
//
};
//   ==============================
//   (3)Smart Power Strip
struct SmartPowerStrip
{
//   5 properties:
//      1) network address(ip address/netmask/gateway/dns)
         struct networkConfig
         {
            int ipAddress[4]; 
            int netmask[4];
            int gateway[4];
            bool configured;
            bool online;
         };


//      2) list of individual socket states (on/off) 

         struct socketState
         {
            bool enabled;
            bool toggling;
            int countDownForToggle;
            bool somethingPullingPower;
            double powerConsumed;
         };

         socketState sockets[8]; // 8 socket power strip


//      3) stored history of power consumption per socket 

         struct powerDataPoint
         {
            double uptime;
            double powerConsumed=0.0;
            bool   socketState; // true = on, false = off
         };

//      4) stored history of socket state changes
         
        powerDataPoint socketHistory[32768];

//      5) stored 'uptime' value

        double uptime; 

//   3 things it can do:
//      1) change individual socket state: on-to-off,off-to-on,toggle/bounce

         void socketOff( int socket );
         void socketOn(  int socket );
         void socketToggle( int socket, float waitBeforeOn );
         bool getSocketState( int socket );

//      2) perform global socket change: all on, all off, all toggle/bounce

         void allSocketOn();
         void allSocketOff();
         void allSocketToggle( float waitBeforeOn );

//      3) reconfigure network settings
         void setIP( networkConfig newConfig );
};

//   ==============================
//   (4)Kitchen Droid
struct KitchenDroid
{
//   5 properties:
//      1) Left/Right armature hardware installed: none, or one of several kitchen tool ID(s) assigned/loaded.
         struct droidArmature
         {
            bool   toolLoaded;
            int    loadedToolID;
            int    currentAction;
            double powerDeliveredToTool;
            double rateOfMovement;
            double segmentRotationX[3];
            double segmentRotationY[3];
            double segmentRotationZ[3];
         };

         droidArmature droidArms[2];

//      2) Inventory of alternate hardware(s) swappable. 
         struct droidTools
         {
            char   name[255];
            int    toolFeature;
            double toolPositionX, toolPositionY, toolPositionZ;
            bool   toolUsesPower;
         };

         droidTools availableTools[255];

//      3) List of activities performable with arm/tools 

         struct armActions
         {
            char name[255];
            int  toolIDNeeded;
            droidArmature armChanges;
         };

         struct armSequences
         {
            char name[255];
            armActions sequence[32768];
         };

         armSequences availableActions[32768]; 

//      4) List of ingredients in stock





//      5) Menu of dishes Kitchen Droid can make


//   3 things it can do:
//      1) Prepare Meal From Menu

//      2) Swap tools

//      3) Validate menu choice with available tools, ingredients,and actions available. 


};


//   ==============================
//   (5)Apple Store
struct AppleStore
{
//   5 properties:
//      1) Inventory of Apple products
//      2) Location
//      3) Hours of operation
//      4) Number of staff
//      5) Hourly Profit
//   3 things it can do:
//      1) Sell Apple Products To New Customers
//      2) Sell Apple Products To Existing Customers
//      3) Collect Money
};
//
//   ==============================
//   (6)Wild Squirrel
struct WildSquirrel
{
//   5 properties:
//      1) Number of nuts in mouth
//      2) Number of trees visited per hour
//      3) Has Jumped In Baby Carriage in Lifetime (bool)
//      4) Is Sprinting(bool)
//      5) Is Chittering(bool)
//   3 things it can do:
//      1) Place Nut In Mouth
//      2) Sprint to random location (inclusive of baby carriages)
//      3) Chitter for random length of time.
};
//
//   ==============================
//   (7)Dungeon Master 
struct DungeonMaster
{
//   5 properties:
//      1) List of voices and personas capable of enacting
//      2) List of various dice to roll for actions/effects
//      3) List of ideas on how to manipulate the party
//      4) List of documents and reference books on hand
//      5) List of player penalties for being difficult *cough*blue lightning*cough*
//   3 things it can do:
//      1) Enact voices and personas to party
//      2) Request the party "roll for initiative"
//      3) Laugh maniacally
};
//
//   ==============================
//   (8)D&D Party Members
struct DNDPartyMembers
{
//   5 properties:
//      1) Player character stats/attributes(age, sex, race, armor class, pasive perception, etc)
//      2) Assortment of dice for rolling for actions and effects
//      3) Is a murderhobo (bool) (senselessly killing non-player-characters in game)
//      4) Fearful of Dungeon Master (bool)
//      5) How badly they want to kill "that partymember" (double)
//   3 things it can do:
//      1) Fulfill quests
//      2) Listen to the dungeon master's amazing voices
//      3) Roll for initiative
};
//
//   ==============================
//   (9)Self Checkout Register
struct SelfCheckoutRegister
{
//   5 properties:
//      1) has screen for user interface
//      2) has scanner for products
//      3) has scale for bagging and validation of products
//      4) has payment interface
//      5) has receipt printer
//   3 things it can do:
//      1) ring up item
//      2) accept payment
//      3) print receipt
};
//   ==============================
//   (10)Gaming Store
struct GamingStore
{
//   5 properties:
//      1) [Self Checkout Register]
//      2) [Microwave]
//      3) [D&D Party Members]
//      4) [Dungeon Master]
//      5) [Smart Power Strip]
//   3 things it can do:
//      1) Host Game Sessions   (for the dungeon masters and d&d players, microwave for food)
//      2) Sell Gaming Supplies (dice, paper, books, self-checkout)
//      3) Users can pay for power (smart power strip, self-checkout)
};





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
