# ConsoleTools
Helpful utilities for pleasant development

- ConsoleColorer 
![ConsoleColorer Demo](/ColorsDemo.png)
 - Usage: 
```
	using namespace std;
	using namespace Colorer;
	
	PrintDemoPalette();
	cout<<"\n";
	cout << Colored(Red) << "Red Warning Text! " << Colored(Yellow) << "Lemons!\n";
	cout << "This text is normal again!\n";
	cout << Colored(BackgroundColor(Gray) | FontColor(Blue)) << "This is blue text on gray background!\n";
```
