 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

// ==================================
// WingTangWong's UDT(s)
// ==================================

#define MAX_NAME_LENGTH 255
#define MAX_LOG_LENGTH  32768
#define MAX_ID          32768
#define MAX_ACTIONS     32768
#define MAX_DESC_LENGTH 32768

// ==============================
// (1)Drive Thru Coffee Stand
struct DriveThruCoffeeStand
{
    // 5 properties:
    // 1) physical attributes (location, dimensions, color, size, orientation)
    // 2) open for business or not (boolean or array of times to be checked against)
    double longitude     = 37.331796;
    double latitude      = -122.0296753;
    float  orientation   = 180.00;
    double width         = 512.000;
    double length        = 512.000;
    double height        = 512.000;
    int    colorRed      = 200;
    int    colorGreen    = 200;
    int    colorBlue     = 200;
    bool openForBusiness = true;

    // 3) stores inventory of consumables
    struct InventoryItem
    {
        char name[MAX_NAME_LENGTH];
        int  numberInStock;
        int  numberOnOrder;
        float pricePerItem;
        float itemWeight;
        bool perishable;
    };

    InventoryItem storeInventory[MAX_ID]; // would we ever need more than 32767 different items?


    struct MenuItem
    {
        char name[MAX_NAME_LENGTH];
        int requiredIngredient; // this would be an inventory item ID number
    };

    MenuItem availableProducts[MAX_ID]; // that's a huge menu... actually, multiple entries for the same item for multi-ingredient
    // recipes.


    // 4) stores financial transactions
    struct IndividualSale
    {
        int timeOfSale;
        int transactionID;
        int itemID;
        bool refunded;
    };

    IndividualSale financialTransactions[MAX_LOG_LENGTH]; // I'm sure this will be fine....

    // 5) stores daily business metrics

    struct DailyMetric
    {
        float grossSales;
        float netProfits;
        float totalRefunded;
    };

    DailyMetric businessLog[MAX_LOG_LENGTH];

    // 3 things it can do:
    // 1) take orders
    bool takeOrder( MenuItem orderItem ); // returns false if the order is invalid, true if the order is valid

    // 2) produce goods for order
    bool createProductAndUpdateInventory( MenuItem orderItem );
    // 3) accept payment for goods
    bool processPayment( IndividualSale tx, DailyMetric log );
};

// ==============================
// (2)Microwave
struct Microwave
{
    // 5 properties:
    // 1) wattage
    float wattage;

    // 2) plugged in or not
    bool powerAvailable;
    // 3) active or not
    bool active;

    // 4) current settings
    int powerLevel;

    // 5) time remaining
    float remainingTime;



    // 3 things it can do:
    // 1) open/close door
    void doorChangeState( bool openDoor );

    // 2) set time/power levels
    void setPowerLevel( int newPowerLevel );
    void setTimer( int newTimeRemaining );

    // 3) start/stop
    void startMicrowave();
};

// ==============================
// (3)Smart Power Strip
struct SmartPowerStrip
{
    // 5 properties:
    // 1) network address(ip address/netmask/gateway/dns)
    struct NetworkConfig
    {
        int ipAddress[4];
        int netmask[4];
        int gateway[4];
        bool configured;
        bool online;
    };

    // 2) list of individual socket states (on/off)

    struct SocketState
    {
        bool enabled;
        bool toggling;
        int countDownForToggle;
        bool somethingPullingPower;
        double powerConsumed;
    };

    SocketState sockets[8]; // 8 socket power strip


    // 3) stored history of power consumption per socket

    struct PowerDataPoint
    {
        double uptime;
        double powerConsumed = 0.0;
        bool   socketState; // true = on, false = off
    };

    // 4) stored history of socket state changes

    PowerDataPoint socketHistory[MAX_LOG_LENGTH];

    // 5) stored 'uptime' value

    double uptime;

    // 3 things it can do:
    // 1) change individual socket state: on-to-off,off-to-on,toggle/bounce

    void socketOff( int socket );
    void socketOn(  int socket );
    void socketToggle( int socket, float waitBeforeOn );
    bool getSocketState( int socket );

    // 2) perform global socket change: all on, all off, all toggle/bounce

    void allSocketOn();
    void allSocketOff();
    void allSocketToggle( float waitBeforeOn );

    // 3) reconfigure network settings
    void setIP( NetworkConfig newConfig );
};

// ==============================
// (4)Kitchen Droid
struct KitchenDroid
{
    // 5 properties:
    // 1) Left/Right armature hardware installed: none, or one of several kitchen tool ID(s) assigned/loaded.
    struct DroidArmature
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

    DroidArmature droidArms[2];

    // 2) Inventory of alternate hardware(s) swappable.
    struct DroidTools
    {
        char   name[MAX_NAME_LENGTH];
        int    toolFeature;
        double toolPositionX, toolPositionY, toolPositionZ;
        bool   toolUsesPower;
    };

    DroidTools availableTools[MAX_NAME_LENGTH];

    // 3) List of activities performable with arm/tools

    struct ArmActions
    {
        char name[MAX_NAME_LENGTH];
        int  toolIDNeeded;
        DroidArmature armChanges;
    };

    struct ArmSequences
    {
        char name[MAX_NAME_LENGTH];
        ArmActions sequence[MAX_ACTIONS];
    };

    ArmSequences availableActions[MAX_ACTIONS];

    // 4) List of ingredients in stock

    struct Ingredient
    {
        char name[MAX_NAME_LENGTH];
        double amountAvailable;
    };

    Ingredient kitchenInventory[MAX_ID];


    // 5) Menu of dishes Kitchen Droid can make

    struct Recipes
    {
        Ingredient ingredientsNeeded[MAX_ID];
        int toolUsed;
    };

    Recipes kitchenRecipes[MAX_ID];

    // 3 things it can do:
    // 1) Prepare Meal From Menu
    void prepareMeal( int recipe );
    // 2) Swap tools
    bool swapTool( int toolID, int armID );

    // 3) Validate menu choice with available tools, ingredients,and actions available.
    bool canPrepare( int recipe );
};


// ==============================
// (5)Apple Store
struct AppleStore
{
    // 5 properties:
    // 1) Inventory of Apple products
    struct AppleItem
    {
        char name[MAX_NAME_LENGTH];
        float price;
        int numberInStock;
    };

    // 2) Location
    // 3) Hours of operation
    //
    struct Hours
    {
        int openingHour;
        int closingHour;
    };

    struct Location
    {
        char name[MAX_NAME_LENGTH];
        Hours storeHours[7];
        AppleItem inventory[MAX_ID];
    };

    // 4) Number of staff
    struct Staff
    {
        char name[MAX_NAME_LENGTH];
        int storeLocation;
        int payGrade;
        Hours schedule[7];
    };

    Staff appleEmployees[MAX_ID];

    // 5) Hourly Profit
    struct Transactions
    {
        int storeLocation;
        double transactionMoment;
        double transactionAmount;
        int appleItemsInTransaction[MAX_LOG_LENGTH];
    };

    Transactions appleStoreTransactions[MAX_LOG_LENGTH];

    struct HourlyProfits
    {
        int storeLocation;
        int hour;
        double timeframe;
        double grossSales;
        double netProfit;
    };

    HourlyProfits appleStoreHourlyProfits[MAX_ID];

    // 3 things it can do:
    // 1) Sell Apple Products To New Customers

    void sellAppleProductToNewCustomer( int storeLocation, int itemID[MAX_ID] );

    // 2) Sell Apple Products To Existing Customers

    void sellAppleProductToExistingCustomer( int storeLocation, int customerID, int itemID[MAX_ID], int existingSalesHistory );

    // 3) Collect Money
    bool collectMoney( int storeLocation, int customerID, int transactionID );

};
//
// ==============================
// (6)Wild Squirrel
struct WildSquirrel
{
    // 5 properties:
    // 1) Number of nuts in mouth
    int nutsInMouth;
    // 2) Number of trees visited per hour
    int treesVisitedPerHour;
    // 3) Has Jumped In Baby Carriage in Lifetime (bool)
    bool visitedBabyCarriage;
    // 4) Is Sprinting(bool)
    bool isSprinting;
    // 5) Is Chittering(bool)
    bool isChittering;

    // 3 things it can do:
    // 1) Place Nut In Mouth
    bool placeNutInMouth(); // might fail...
    // 2) Sprint to random location (inclusive of baby carriages)
    bool sprintToRandomLocation(); // might fail
    // 3) Chitter for random length of time.
    float performChittering(); // returns random value indicating how long chittering will go on for

};
//
// ==============================
struct Dice
{
    char name[MAX_NAME_LENGTH]; // yes... some dice get names...
    int numberOfSides;
};



// (7)Dungeon Master
struct DungeonMaster
{
    // 5 properties:
    // 1) List of voices and personas capable of enacting
    struct Voice
    {
        char name[MAX_NAME_LENGTH];
        char gender;
        char description[MAX_DESC_LENGTH];
    };

    Voice dungeonMasterVoices[MAX_ID];

    // 2) List of various dice to roll for actions/effects
    Dice bagOfDice[MAX_ID];

    // 3) List of ideas on how to manipulate the party
    struct Ideas
    {
        char name[MAX_NAME_LENGTH];
        char description[MAX_DESC_LENGTH];
    };

    Ideas dungeonMasterIdeas[MAX_ID];

    // 4) List of documents and reference books on hand

    struct Document
    {
        char name[MAX_NAME_LENGTH];
        char sourceMaterial[MAX_NAME_LENGTH];
        char dungeonMasterNotes[MAX_DESC_LENGTH];
    };

    Document dungeonMasterReferences[MAX_ID];

    // 5) List of player penalties for being difficult *cough*blue lightning*cough*

    struct Annoyances
    {
        char name[MAX_NAME_LENGTH];
        char description[MAX_DESC_LENGTH];
    };

    Annoyances dungeonMasterPetPeeves[MAX_ID];

    struct Penalties
    {
        char name[MAX_NAME_LENGTH]; // it might involve blue lightning... just saying..
        char description[MAX_DESC_LENGTH];
        Dice damageExpected[MAX_ID]; // how many dice... is too much?
    };

    Penalties dungeonMasterPenalties[MAX_ID];


    // 3 things it can do:
    // 1) Enact voices and personas to party

    void performCoolVoice( int voiceID , int situationID );

    // 2) Request the party "roll for initiative"

    void requestRollForInitiative();

    // 3) Laugh maniacally

    void executeManiacalLaugh(int laughID );

};
//
// ==============================
// (8)D&D Party Members
struct DNDPartyMembers
{
    // 5 properties:
    // 1) Player character stats/attributes(age, sex, race, armor class, pasive perception, etc)
    struct PlayerStats
    {
        char name[MAX_NAME_LENGTH];
        char race[MAX_NAME_LENGTH];
        int  experiencePoints;
        int  intelligence;
        int  wisdom;
        int  charisma;
        int  dexterity;
        int  constitution;
        int  strength;
        int  hitPoints;
        int  armorClass;
        int  passivePerception;
        int  initiativeBonus;
        int  level;
    };
    // 2) Assortment of dice for rolling for actions and effects
    Dice bagOfDice[MAX_ID];

    // 3) Is a murderhobo (bool) (senselessly killing non-player-characters in game)
    bool murderHobo;

    // 4) Fearful of Dungeon Master (bool)
    bool fearsDungeonMaster;

    // 5) How badly they want to kill "that partymember" (double)
    float partyMemberDeathWish;

    // 3 things it can do:
    // 1) Fulfill quests
    bool pursueQuest(int questID);
    // 2) Listen to the dungeon master's amazing voices
    void enjoyDungeonMasterVoices();
    // 3) Roll for initiative
    int rollForInitiative();
};
//
// ==============================
// (9)Self Checkout Register
struct SelfCheckoutRegister
{
    // 5 properties:
    // 1) has screen for user interface
    struct MenuItem
    {
        char name[MAX_NAME_LENGTH];
        int  menuFunctionID;
    };

    MenuItem userInterfaceOptions[MAX_ID];

    // 2) has scanner for products

    struct ScannerData
    {
        bool validReading;
        int  readBarCodeValue;
    };

    // 3) has scale for bagging and validation of products

    struct StoreItem
    {
        char name[MAX_NAME_LENGTH];
        int  barCode;
        double weight;
        double weightVariance;
        double price;
    };

    struct ShoppingScale
    {
        bool weightValueChange;
        double retrievedValue;
    };

    ShoppingScale transactionWeightLog[MAX_LOG_LENGTH];
    StoreItem     transactionItemLog[MAX_LOG_LENGTH];

    // 4) has payment interface
    struct PaymentOptions
    {
        char name[MAX_NAME_LENGTH];
        int  paymentInterface;
        bool contactLessPayment;
        bool magneticStrip;
        bool smartChip;
    };

    PaymentOptions paymentInterfaceOptions[MAX_ID];

    // 5) has receipt printer

    struct ReceiptPrinter
    {
        bool hasPaper;
        bool online;
        bool transactionStarted;
        bool currentlyPrinting;
        bool readyForNewOutput;
    };

    struct ReceiptEntry
    {
        int itemID;
        double price;
        double tax;
        int discountCode;
        double discountedPrice;
    };

    ReceiptEntry receiptToPrint[MAX_LOG_LENGTH];


    // 3 things it can do:
    // 1) ring up item
    void ringUpItem( int itemID );

    // 2) accept payment
    bool processPayment( int paymentOptionSelected, int transactionID );

    // 3) print receipt
    bool printReceipt( int transactionID );

};
// ==============================
// (10)Gaming Store
struct GamingStore
{
    // 5 properties:
    // 1) [Self Checkout Register]
    SelfCheckoutRegister availableRegisters[MAX_ID];
    DriveThruCoffeeStand gamingStore[MAX_ID];

    // 2) [Microwave]
    Microwave availableMicrowaves[MAX_ID];

    // 3) [D&D Party Members]
    DNDPartyMembers registeredDNDPartyMemberRoster[MAX_ID];

    // 4) [Dungeon Master]
    DungeonMaster registeredDungeonMasterRoster[MAX_ID];

    // 5) [Smart Power Strip]
    SmartPowerStrip availableSmartPowerStrips[MAX_ID];

    // 3 things it can do:
    // 1) Host Game Sessions   (for the dungeon masters and d&d players, microwave for food)
    bool scheduleGamingSession( double desiredStartTime, double desiredEndTime, int partySize, int numberOfTables );

    // 2) Sell Gaming Supplies (dice, paper, books, self-checkout)
    void ringUpSupplies( int registerID, int storeID, int transactionID );

    // 3) Users can pay for power (smart power strip, self-checkout)
    void payForPower( int registerID, int powerStripID, int tableID, int memberID );

};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
