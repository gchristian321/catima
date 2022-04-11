/*
 *  Author: Andrej Prochazka
 *  Copyright(C) 2017
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.

 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPPATIMA_H
#define CPPATIMA_H

#include <utility>
#include <vector>

// #define NDEBUG
#include "catima/build_config.h"
#include "catima/config.h"
#include "catima/constants.h"
#include "catima/structures.h"
#include "catima/calculations.h"
#include "catima/material_database.h"
#include "catima/storage.h"

namespace catima{
    
    /**
      * calculate dEdx for projectile-Material combination
      * @param p - Projectile
      * @param mat - Material
      * @return dEdx
      */
    double dedx(const Projectile &p, const Material &mat, const Config &c=default_config);
    
    /**
      * calculate energy loss straggling variance for projectile-Material combination
      * @param p - Projectile
      * @param t - Material
      * @return dOmega^2/dx
      */
    double domega2dx(const Projectile &p, const Material &t, const Config &c=default_config);

    /**
      * calculates variance of angular scattering of Projectile p on Material m
      */
    double da2dx(const Projectile &p, const Material &m, const Config &c=default_config);

    /**
      * returns the range of the Projectile in Material calculated from range spline
      * @param p - Projectile
      * @param t - Material
      * @return range
      */
    double range(const Projectile &p, const Material &t, const Config &c=default_config);

    /**
      * returns the dEdx calculated from range spline as derivative
      * @param p - Projectile
      * @param t - Material
      * @return range
      */
    double dedx_from_range(const Projectile &p, const Material &t, const Config &c=default_config);

    /**
      * returns the dEdx calculated from range spline as derivative
      * @param p - Projectile
      * @param T - energy vector
      * @param mat - Material
      * @return range
      */
    std::vector<double> dedx_from_range(const Projectile &p, const std::vector<double> &T, const Material &t, const Config &c=default_config);

    /**
      * returns the  range straggling of the Projectile in Material from spline
      * @param p - Projectile
      * @param T - energy in MeV/u
      * @param mat - Material
      * @return range straggling
      */
    double range_straggling(const Projectile &p, double T, const Material &t, const Config &c=default_config);

    /**
      * returns the  range variance of the Projectile in Material from spline
      * @param p - Projectile
      * @param T - energy in MeV/u
      * @param mat - Material
      * @return range straggling
      */
    double range_variance(const Projectile &p, double T, const Material &t, const Config &c=default_config);

    /**
      * returns the  range variance per dE, calculated as derivative of range variance spline
      * @param p - Projectile
      * @param T - energy in MeV/u
      * @param mat - Material
      * @return range variance / dE
      */
    double domega2de(const Projectile &p, double T, const Material &t, const Config &c=default_config);

    /**
      * returns the  angular variance per dE, calculated as derivative of angular variance spline
      * @param p - Projectile
      * @param T - energy in MeV/u
      * @param mat - Material
      * @return angular variance / dE
      */
    double da2de(const Projectile &p, double T, const Material &t, const Config &c=default_config);

    /**
      * returns the planar RMS angular straggling in rad
      * @param p - Projectile
      * @param t - Material class
      * @param c - Config class
      * @return angular RMS straggling in rad
      */
    double angular_straggling(Projectile p, const Material &t, const Config &c=default_config);
    /**
      * returns the planar RMS angular variance in rad
      * @param p - Projectile
      * @param t - Material class
      * @param c - Config class
      * @return angular RMS variance in rad
      */
    double angular_variance(Projectile p, const Material &t, const Config &c=default_config, int order = 0);

    /**
      * calculates angular scattering in the material from difference of incoming a nd outgoing energies
      * @param p - Projectile
      * @param T - incoming energy
      * @param Tout - outcoming energy
      * @param mat - Material
      * @return angular straggling
      */
    double angular_straggling_from_E(const Projectile &p, double T, double Tout,Material t, const Config &c=default_config);

    /**
      * calculates Energy straggling in the material from difference of incoming a nd outgoing energies
      * @param p - Projectile
      * @param T - incoming energy
      * @param Tout - outcoming energy
      * @param mat - Material
      * @return angular straggling
      */
    double energy_straggling_from_E(const Projectile &p, double T, double Tout,const Material &t, const Config &c=default_config);
    
    /**
      * calculates outcoming energy from range spline
      * @param T - incoming energy
      * @thickness - thicnkess of the target in g/cm2
      * @range_spline - precaclulated range spline for material 
      * @return outcoming energy after the thickness in Mev/u
      */
    double energy_out(double T, double thickness, const Interpolator &range_spline);

    /**
      * calculates outcoming energy 
      * @p - Projectile
      * @t - Material
      * @param T - incoming energy
      * @return outcoming energy after the material in Mev/u
      */
    double energy_out(const Projectile &p, const Material &t, const Config &c=default_config);

    /**
      * calculates outcoming energy 
      * @p - Projectile
      * @t - Material
      * @param T - incoming energy vector
      * @return outcoming energy after the material in Mev/u
      */
    std::vector<double> energy_out(const Projectile &p, const std::vector<double> &T, const Material &t, const Config &c=default_config);

    /**
      * calculates incoming energy from range spline
      * @param T - outgoing energy
      * @thickness - thicnkess of the target in g/cm2
      * @range_spline - precaclulated range spline for material 
      * @return incoming energy giving energy T after the thickness in Mev/u
      */
    double energy_in(double T, double thickness, const Interpolator &range_spline);

    /**
      * calculates incoming energy 
      * @p - Projectile
      * @t - Material
      * @param T - outgoing energy
      * @return incoming energy giving energy T after the thickness in Mev/u
      */
    double energy_in(const Projectile &p, const Material &t, const Config &c=default_config);

    /**
      * calculates incoming energy 
      * @p - Projectile
      * @t - Material
      * @param T - outgoing energy vector
      * @return incoming energy after the material in Mev/u
      */
    std::vector<double> energy_in(const Projectile &p, const std::vector<double> &T, const Material &t, const Config &c=default_config);

    /**
      * calculates all observables for projectile passing material
      * @param p - Projectile
      * @param mat - Material
      * @return structure of Result
      */
    Result calculate(Projectile p, const Material &t, const Config &c=default_config);
    inline Result calculate(Projectile p, const Material &t, double T, const Config &c=default_config){
        p.T = T;
        return calculate(p, t, c);
    }

      /**
      * wrapper to other calculate function with simplified arguments
      * @param p - Projectile
      * @param mat - Material
      * @return structure of Result
      */
    Result calculate(double pa, int pz, double T, double ta, double tz, double thickness, double density);


    /**
      * calculate observables for multiple layers of material defined by Layers
      * @return results stored in MultiResult structure
      *
      */
    MultiResult calculate(const Projectile &p, const Phasespace &ps, const Layers &layers, const Config &c=default_config);

    /**
      * calculate observables for multiple layers of material defined by Layers
      * @return results stored in MultiResult structure
      *
      */
    inline MultiResult calculate(const Projectile &p, const Layers &layers, const Config &c=default_config){
      return calculate(p, {}, layers, c);
    };
    inline MultiResult calculate(Projectile p, double T, const Layers &layers, const Config &c=default_config){
        return calculate(p(T), layers, c);
    }

 
    /// this calculate tof spline, at the moment it is not used
    std::vector<double> calculate_tof(const Projectile p, const Material &t, const Config &c=default_config);
    
    /**
      * calculates TOF of the Projectile in Material
      * this is used instead of precalculated TOF spline
      * @return TOF in ns
      */
    double calculate_tof_from_E(Projectile p, double Eout, const Material &t, const Config &c=default_config);
    
    /**
     * returns energy magnification after passing material t
     */
    std::pair<double,double> w_magnification(const Projectile &p, double Ein, const Material &t, const Config &c=default_config);

    class DataPoint;
    /**
      * calculates DataPoint for Projectile Material combinatino
      * it substitute series of calls to calculate_* functions
      * they are all combined here in 1 single function
      * it has a perfomance gain to call this function if all splines are to be caclulated
      */
    DataPoint calculate_DataPoint(Projectile p, const Material &t, const Config &c=default_config);

    bool operator==(const Config &a, const Config&b);
}
#endif
