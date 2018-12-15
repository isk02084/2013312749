#!/bin/bash

mkdir -p ./result

if [ $1 = "resource" ]
then
	mkdir -p ./result/resource
	if [ $2 = "book" ]
	then
		echo -e "Type\tName" > result/resource/book.dat
		while read A B
		do
			if [ $A = "Book" ]
			then
				echo -e "$A\t$B" >> result/resource/book.dat
			fi
		done < ./resource.dat
	elif [ $2 = "e-book" ]
	then
		echo -e "Type\tName" > result/resource/e-book.dat
		while read A B
		do
			if [ $A = "E-book" ]
			then
				echo -e "$A\t$B" >> result/resource/e-book.dat
			fi
		done < ./resource.dat
	elif [ $2 = "magazine" ]
	then
		echo -e "Type\tName" > result/resource/magazine.dat
		while read A B
		do
			if [ $A = "Magazine" ]
			then
				echo -e "$A\t$B" >> result/resource/magazine.dat
			fi
		done < ./resource.dat
	elif [ $2 = "all" ]
	then
		echo -e "Type\tName" > result/resource/book.dat
		while read A B
		do
			if [ $A = "Book" ]
			then
				echo -e "$A\t$B" >> result/resource/book.dat
			fi
		done < ./resource.dat
		echo -e "Type\tName" > result/resource/e-book.dat
		while read A B
		do
			if [ $A = "E-book" ]
			then
				echo -e "$A\t$B" >> result/resource/e-book.dat
			fi
		done < ./resource.dat
		echo -e "Type\tName" > result/resource/magazine.dat
		while read A B
		do
			if [ $A = "Magazine" ]
			then
				echo -e "$A\t$B" >> result/resource/magazine.dat
			fi
		done < ./resource.dat
	fi

elif [ $1 = "input" ]
then
	mkdir -p ./result/input
	cp ./input.dat ./input.bak
	cp ./space.dat ./space.bak
	rm ./space.dat
	
	if [ $2 = "book" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $r_t = "Book" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/book.dat
	
	elif [ $2 = "magazine" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $r_t = "Magazine" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/book.dat

	elif [ $2 = "undergraduate" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Undergraduate" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/book.dat
	elif [ $2 = "graduate" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Graduate" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/book.dat
	elif [ $2 = "faculty" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Faculty" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/book.dat
	fi

	cp ./space.bak ./space.dat
	cp ./input.bak ./input.dat
	rm ./input.bak
	rm ./space.bak
	./library

elif [ $1 = "space" ]
then
	mkdir -p ~/2013312749/result space
	cp ./input.dat ./input.bak
	cp ./space.dat ./space.bak
	rm ./input.dat

	cp ./space.bak ./space.dat
	cp ./input.bak ./input.dat
	rm ./input.bak
	rm ./space.bak

elif [ $1 = "output" ]
then
	mkdir -p ~/2013312749/result output

fi