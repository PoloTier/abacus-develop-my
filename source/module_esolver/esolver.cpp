#include "esolver.h"
#include "esolver_ks_pw.h"
#include "esolver_sdft_pw.h"
#include "esolver_ks_lcao.h"
#include "esolver_ks_lcao_tddft.h"
#include "esolver_of.h"
#include "esolver_lj.h"
#include "esolver_dp.h"

namespace ModuleESolver
{
    void ESolver::printname()
    {
        std::cout << classname << std::endl;
    }


    //Some API to operate E_Solver
    void init_esolver(ESolver*& p_esolver, const string use_esol)
    {
        if (use_esol == "ksdft_pw")
        {
            p_esolver = new ESolver_KS_PW();
        }
        else if (use_esol == "ksdft_lcao")
        {
            p_esolver = new ESolver_KS_LCAO();
        }
        else if (use_esol == "ksdft_lcao_tddft")
        {
            p_esolver = new ESolver_KS_LCAO_TDDFT();
        }
        else if (use_esol == "sdft_pw")
        {
            p_esolver = new ESolver_SDFT_PW();
        }
        //  else if(use_esol == "ofdft")
        //  {
        //      p_esolver = new OFDFT();
        //  }
        else if (use_esol == "lj_pot")
        {
            p_esolver = new ESolver_LJ();
        }
        else if (use_esol == "dp_pot")
        {
            p_esolver = new ESolver_DP();
        }
    }

    void clean_esolver(ESolver*& pesolver)
    {
        delete pesolver;
    }

}
