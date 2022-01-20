
#pragma once
#include "wx/wx.h"
#include <wx/grid.h>
#include <wx/radiobox.h>
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	wxButton* submit = nullptr;
	wxTextCtrl* answer = nullptr;
	wxStaticText* question = nullptr;
	wxStaticText* result = nullptr;
	wxPanel* panel = nullptr;


	void SubmitAnswer(wxCommandEvent& evt);
	void ChangeText(int i);
	void CheckAnswer(int i, wxString ans);


	wxDECLARE_EVENT_TABLE();

};
	
