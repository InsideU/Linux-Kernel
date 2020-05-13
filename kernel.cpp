
void printf(char* str){
	unsigned short* VideoMemory =(unsigned short*)0xb8000; //storing the charater on memory 
	for(int i=0;str[i]!='\0';++i)				// o fuck but we will overwrite the color as well the black screen with white text	
		VideoMemory[i]=(VideoMemory[i] & 0xFF00) | str[i];  // ok so we can store them as well using the memory 0xFF00 now both 2 bytes are safe 
}
// I am still getting a problem compiler is assuming that there is a glibc so we have to tell me stop that shit so move to make file

extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber){
	//The interesting thing here is we do not have any printf command to write the output on the screen . O wait that sucks why the heck they dont make one 
	//as we do not have an operating sytem so there is not dynamic linking between the glibc libraries of c 
	//and the c library is not available that can be loaded here because we make other people work easy not other developers works easy 
	//so we need to write our own printf command so the we can print the output in the screen so lets dive in 
	//Never thought i will have to write something that will execute printf . Now i guess i will think before using printf and cout in competitive programming LOL
	printf("Umang's os booting up  Hold on"); 
	while(1);
}


// 0xb8000 is the memory location that is printed on the screen and the color white text on backgroud is present in this location . Thank god ECE people saved us form that
//
