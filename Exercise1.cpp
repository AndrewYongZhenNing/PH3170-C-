int globalVar = 25;

int main(){
  int varA = 10*globalVar;

  int varB = (15*varA)/globalVar;

  int varC = varB*varB;
  int varD = varA*globalVar;
  int varC = (varB*varD)/varA;
}
