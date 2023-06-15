#include "menu.h"
static uint8_t tag_line[]  = "bi0s Hardware";
static uint8_t lab_0_Desc[]  ="  Introducing the breathtaking coastal retreat, Ocean Haven. Nestled amidst lush palm trees and overlooking pristine turquoise waters, this luxurious paradise offers an unparalleled escape from the ordinary. Immerse yourself in the serenity of your private villa, adorned with elegant furnishings and state-of-the-art amenities. Wake up to the gentle sound of waves crashing and indulge in a delectable breakfast on your expansive ocean-facing terrace. Dive into the sparkling infinity pool or stroll along the secluded white sandy beach, basking in the warmth of the sun. Unwind with a rejuvenating spa treatment or embark on thrilling aquatic adventures.";
static uint8_t lab_1_Desc[]  ="  Experience pure opulence at The Royal Emerald, a luxurious haven nestled in the heart of a vibrant city. This exquisite retreat combines contemporary elegance with timeless charm, offering a truly captivating experience. Step into the grand lobby, adorned with stunning chandeliers and lavish furnishings, and be greeted by attentive staff ready to cater to your every need. Immerse yourself in the lavish comfort of your spacious suite, featuring plush bedding, sleek marble bathrooms, and panoramic views of the city skyline. Indulge in gourmet dining at the award-winning restaurant, where expert chefs create culinary masterpieces to tantalize your taste buds.";

///////////////////////////////////////////////////////////

static uint8_t lab_0[]  =" What is a title?";
static uint8_t lab_1[]  =" This is another title";

#define ISBOLD      0b00000010
#define ISUNDERLINE 0b00000001

Menuitem menu[] = {   //(isbold | isUnderline) 
    {lab_0 , lab_0_Desc,  (ISBOLD| ISUNDERLINE), LEN(lab_0) , LEN(lab_0_Desc)},
    {lab_1 , lab_1_Desc,  (ISBOLD| ISUNDERLINE), LEN(lab_1) , LEN(lab_1_Desc)}};