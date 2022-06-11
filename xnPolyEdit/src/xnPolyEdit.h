#ifndef STRAIGHTSKELETON_H
#define STRAIGHTSKELETON_H

#include <vector>

#include "xnModule.h"
#include "xnCommon.h"
#include "xnGeometry.h"
#include "xnRenderer.h"
#include "xnLineProperties.h"
#include "xnModuleInitData.h"

namespace xn
{
  class Logger;
  class Renderer;

  class PolyEdit : public xn::Module
  {
  public:

    PolyEdit(xn::ModuleInitData *);

    void Render(xn::Renderer *pRenderer, xn::mat33 const &T_World_View) override;
    void Clear();

    bool SetGeometry(xn::PolygonGroup const &) override;

  private:

    void _DoFrame(xn::UIContext *) override;

  };
};

#endif