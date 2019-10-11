#ifndef __c77_GTF_EnginePath_TwoSpool_h__
#define __c77_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc77_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc77_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c77_sfEvent;
  boolean_T c77_isStable;
  boolean_T c77_doneDoubleBufferReInit;
  uint8_T c77_is_active_c77_GTF_EnginePath_TwoSpool;
  real_T *c77_W44;
  real_T *c77_Tt44;
  real_T *c77_WcoolHPT;
  real_T *c77_Tt3;
  real_T *c77_Tt45;
  real_T *c77_Sfcn45;
  real_T *c77_Wf;
  real_T *c77_W45;
} SFc77_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc77_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c77_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c77_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c77_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
