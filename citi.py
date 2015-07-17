#!/bin/python
archi=open("datos.txt","w")
archi.close()
archi=open("datos.txt",'a')
lista=["salina","tehuantepec","juchitan","oaxaca","ixtepec","ixtaltepec","tonala","pijijiapan","huixtla","tapachula","tuxtla","villahermosa","comitan","sancristo","ocosingo","palenque","huatulco","ptoesco","puebla","cardenaz","cdcarmen","campeche","merida","cancun","playa","chetumal","coatza","minatitlan","acayucan","cordoba","orizaba","cdmex","veracruz","xalapa","pozarica","tuxpan","tampico","matamoros","reynosa"]
infile=open("rut.txt",'r')
arc=open("city.txt","w")



for line in infile:
	st=line
	ar=st.split(',')
	cad1=ar[0]
	print(cad1)
	cad2=ar[1].strip()
	print(cad2)
	ind1=lista.index(cad1)
	print(ind1)
	ind2=lista.index(cad2)
	print(ind2)
	inst1=str(ind1)
	inst2=str(ind2)
	archi.write("matriz["+inst1+"]["+inst2+"]=1;")
	archi.write("matriz["+inst2+"]["+inst1+"]=1;")
	archi.write("\n")
archi.close()
num=0
for ci in lista:
	l=str(num)
	c=str(0)
	arc.write("list["+l+"]["+c+"]=\""+ci+"\";\n")
	arc.write
	num=num+1

arc.close()



