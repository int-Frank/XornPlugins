
#include <windows.h>

#include "xnPolyEdit.h"
#include "xnGeometricQueries.h"
#include "xnPluginAPI.h"
#include "xnVersion.h"
#include "xnLogger.h"

using namespace xn;

DEFINE_STANDARD_EXPORTS
DEFINE_DLLMAIN

Module *xnPlugin_CreateModule(xn::ModuleInitData *pData)
{
  return new xn::PolyEdit(pData);
}

char const *xnPlugin_GetModuleName()
{
  return "Polygon Editor";
}

PolyEdit::PolyEdit(xn::ModuleInitData *pData)
  : Module(pData)
{

}

bool PolyEdit::SetGeometry(PolygonGroup const &geometry)
{
  return true;
}

void PolyEdit::_DoFrame(UIContext *pContext)
{
  if (pContext->Button("What is this?##PolyEdit"))
    pContext->OpenPopup("Description##PolyEdit");
  if (pContext->BeginPopup("Description##PolyEdit"))
  {
    float wrap_width = 400.f;
    pContext->PushTextWrapPos(pContext->GetCursorPos().x() + wrap_width);
    pContext->Text("This module allows you to edit the project polygons.", wrap_width);
    pContext->PopTextWrapPos();
    pContext->EndPopup();
  }
}

void PolyEdit::Render(Renderer *pRenderer, mat33 const &T_World_View)
{

}