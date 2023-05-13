// {
// "people":[
//     {"id":1, "name":"Yaron"},
//     {"id":2, "name":"Kami"},
//     {"id":3, "name":"Omri"},
//     {"id":4, "name":"Bonti"},
//     {"id":5, "name":"Yuval"}
// ] 

// }
#include <Adafruit_Fingerprint.h>


const char* id_to_name(uint8_t id){

    const char* name = ""; ; // unassigned char variable


    switch (id) {
    case 1:
        name = "Yaron";
        break;
    case 2:
        name = "";//dont change
        break;
    case 3:
        name = "Omri";
        break;
    case 4:
        name = "Bonti";
        break;
    case 5:
        name = "Doron";
        break;
    case 6:
        name = "Kami";
        break;
    case 7:
        name = "Kami";
        break;

        
    default:
        name = "";
        break;
}


return name;

}



