#include "cMain.h"
#include <list>
#include <iostream>

using namespace std;

wxBEGIN_EVENT_TABLE(cMain, wxFrame)	
EVT_BUTTON(1, SubmitAnswer)

wxEND_EVENT_TABLE()

list<string> questions = { "When one", "when 2", "when 3"};
list<string> answers = { "Answer1", "answer2", "answer3" };

int index = 0;
wxString userinput;


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Bucuria Craciunului", wxPoint(30, 30), wxSize(300, 400))
{

	submit = new wxButton(this, 1, "Submit", wxPoint(65, 35), wxSize(70, 90));
	answer = new wxTextCtrl(this, 2);
	question = new wxStaticText(this, 3, "when blah blah?", wxPoint(65, 140));
	result = new wxStaticText(this, 3, "youranswer", wxPoint(65, 190));


	submit->SetFont(wxFont(18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	ChangeText(index);
}



cMain::~cMain()
{
	
}	

void cMain::ChangeText(int i) {

	list<string>::iterator questions_it = questions.begin();

	advance(questions_it, i);

	question->SetLabel(*questions_it);
	question->Refresh();

}

void cMain::CheckAnswer(int i, wxString ans) {
	list<string>::iterator answers_it = answers.begin();
	advance(answers_it, i);

	if (ans == *answers_it) {
		result->SetLabel("Correct");
		result->Refresh();
	}
	else {
		result->SetLabel("Tf nigga");
		result->Refresh();
	}
}

void cMain::SubmitAnswer(wxCommandEvent& evt){
	index++;
	ChangeText(index);
	userinput = answer->GetValue();
	CheckAnswer(index, userinput);
}
