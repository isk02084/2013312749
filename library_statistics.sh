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
	
	elif [ $2 = "e-book" ]
	then
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $r_t = "E-book" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/e-book.dat

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
		cp ./output.dat ./result/input/magazine.dat

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
		cp ./output.dat ./result/input/undergraduate.dat
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
		cp ./output.dat ./result/input/graduate.dat
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
		cp ./output.dat ./result/input/faculty.dat

	elif [ $2 = "all" ]
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
		cp ./input.bak ./input.dat
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $r_t = "E-book" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/e-book.dat
		cp ./input.bak ./input.dat
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $r_t = "Magazine" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/magazine.dat
		cp ./input.bak ./input.dat
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Undergraduate" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/undergraduate.dat
		cp ./input.bak ./input.dat
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Graduate" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/graduate.dat
		cp ./input.bak ./input.dat
		echo -e "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" > ./input.dat
		while read dat r_t r_n oper m_t m_n 
		do	
			if [ $m_t = "Faculty" ]
			then
				echo -e "$dat\t$r_t\t$r_n\t$oper\t$m_t\t$m_n" >> ./input.dat
			fi
		done < ./input.bak
		./library
		cp ./output.dat ./result/input/faculty.dat

	fi

	cp ./space.bak ./space.dat
	cp ./input.bak ./input.dat
	rm ./input.bak
	rm ./space.bak
	./library

elif [ $1 = "space" ]
then
	mkdir -p ./result/space
	cp ./input.dat ./input.bak
	cp ./space.dat ./space.bak
	rm ./input.dat

	if [ $2 = "studyroom" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $s_t = "StudyRoom" ]
			then
				if [ $3 = "all" ]
				then
					echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
				else
					if [ $3 = $s_n ]
					then
						echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
					fi
				fi
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/studyroom.dat

	elif [ $2 = "seat" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $s_t = "Seat" ]
			then
				if [ $3 = "all" ]
				then
					echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
				else
					if [ $3 = $s_n ]
					then
						echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
					fi
				fi
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/seat.dat

	elif [ $2 = "undergraduate" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Undergraduate" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/undergraduate.dat

	elif [ $2 = "graduate" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Graduate" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/graduate.dat
	
	lif [ $2 = "faculty" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Faculty" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/faculty.dat
	
	elif [ $2 = "all" ]
	then
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $s_t = "StudyRoom" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/studyroom.dat
		cp ./space.bak ./space.dat
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $s_t = "Seat" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/seat.dat
		cp ./space.bak ./space.dat
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Undergraduate" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/undergraduate.dat
		cp ./space.bak ./space.dat
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Graduate" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/graduate.dat
		cp ./space.bak ./space.dat
		echo -e "Date[yy/mm/dd/hh]\tSpace_type\tSpace_number\tOperation\tMember_type\tMember_name\tNumber_of_member\tTime" > ./space.dat
		while read dat s_t s_n oper m_t m_n n_m tim
		do	
			if [ $m_t = "Faculty" ]
			then
				echo -e "$dat\t$s_t\t$s_n\t$oper\t$m_t\t$m_n\t$n_m\t$tim" >> ./space.dat
			fi
		done < ./space.bak
		./library
		cp ./output.dat ./result/space/faculty.dat

	fi

	cp ./space.bak ./space.dat
	cp ./input.bak ./input.dat
	rm ./input.bak
	rm ./space.bak

elif [ $1 = "output" ]
then
	mkdir -p ./result/output

fi