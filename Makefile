
pgm = bruttoRechner
#sources = bruttoRechner.c eingabe.c kontrolle_der_eingabe.c get_lohnsteuer.c get_soli.c get_kirchen.c mpara.c
objects= bruttoRechner.o eingabe/eingabe.o eingabe/kontrolle_der_eingabe.o lr_19_MW/MainProgramme/mpara.o user/new_daten.o lr_19_MW/MainProgramme/mre4jl.o lr_19_MW/MainProgramme/mre4.o lr_19_MW/UnterProgramme/tab.o lr_19_MW/MainProgramme/mre4alte.o lr_19_MW/MainProgramme/mre4abz.o lr_19_MW/MainProgramme/mberech.o lr_19_MW/MainProgramme/mztabfb.o lr_19_MW/MainProgramme/msolz.o lr_19_MW/MainProgramme/mlstjahr.o lr_19_MW/UnterProgramme/uplstlzz.o lr_19_MW/UnterProgramme/upvkvlzz.o lr_19_MW/UnterProgramme/upanteil.o lr_19_MW/UnterProgramme/upevp.o lr_19_MW/UnterProgramme/upmlst.o lr_19_MW/UnterProgramme/upvkv.o lr_19_MW/MainProgramme/mvsp.o lr_19_MW/UnterProgramme/uptab19.o lr_19_MW/MainProgramme/mst5_6.o lr_19_MW/UnterProgramme/up5_6.o lr_19_MW/MainProgramme/msonst.o lr_19_MW/MainProgramme/mvmt.o lr_19_MW/MainProgramme/mosonst.o lr_19_MW/MainProgramme/mre4sonst.o lr_19_MW/runden/aufrunden_double.o lr_19_MW/runden/abrunden_double.o lr_19_MW/lr_19_MW.o sv_19_MW/sv_19_MW.o sv_19_MW/MainProgramme/sv_pv_19.o sv_19_MW/MainProgramme/sv_kv_19.o sv_19_MW/MainProgramme/sv_av_19.o sv_19_MW/MainProgramme/sv_rv_19.o Funktion/getfile_size.o kst_19_MW/kst_19_MW.o Funktion/lr_parameter_pruefung.o Funktion/datenbank.o sum_19_MW/sum_19_MW.o

#all: clean $(pgm)

$(pgm): $(objects)
	gcc -Wall -Werror -Wpedantic -g -o $@ $^

#mberech.o: mberech.c
#	gcc -g -c mberech.c mztabfb.c mlstjahr.c uplstlzz.c upvkvlzz.c mre4abz.c msolz.c

%.o: %.c
#	gcc -Wall -Werror -Wpedantic -g -c $^
	gcc -Wall -Werror -Wpedantic -g -c $< -o $@

clean:
	rm -f $(objects)

#hier standen vorher noch andere sachen mit der jetzigem ist das nicht gewährleistet das es ein compile vorgang gehen wird
#musste das aber entfernen
