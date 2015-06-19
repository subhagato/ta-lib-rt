/* TA-LIB Copyright (c) 1999-2008, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  103104 AC   Creation           
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode::InternalError)
/* Generated */    namespace TicTacTec { namespace TA { namespace Library {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #include "ta_java_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode.InternalError)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::CdlIdentical3CrowsLookback( void )
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int cdlIdentical3CrowsLookback(  )
/* Generated */ 
/* Generated */ #else
/* Generated */ TA_LIB_API int TA_CDLIDENTICAL3CROWS_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ /* No parameters to validate. */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */
    return max( TA_CANDLEAVGPERIOD(ShadowVeryShort), TA_CANDLEAVGPERIOD(Equal)
            ) + 2;
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLIDENTICAL3CROWS - Identical Three Crows
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED ) && defined( USE_SUBARRAY )
/* Generated */ enum class Core::RetCode Core::CdlIdentical3Crows( int    startIdx,
/* Generated */                                                    int    endIdx,
/* Generated */                                                    SubArray<double>^ inOpen,
/* Generated */                                                    SubArray<double>^ inHigh,
/* Generated */                                                    SubArray<double>^ inLow,
/* Generated */                                                    SubArray<double>^ inClose,
/* Generated */                                                    [Out]int%    outBegIdx,
/* Generated */                                                    [Out]int%    outNBElement,
/* Generated */                                                    SubArray<int>^  outInteger )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::CdlIdentical3Crows( int    startIdx,
/* Generated */                                                    int    endIdx,
/* Generated */                                                    cli::array<double>^ inOpen,
/* Generated */                                                    cli::array<double>^ inHigh,
/* Generated */                                                    cli::array<double>^ inLow,
/* Generated */                                                    cli::array<double>^ inClose,
/* Generated */                                                    [Out]int%    outBegIdx,
/* Generated */                                                    [Out]int%    outNBElement,
/* Generated */                                                    cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode cdlIdentical3Crows( int    startIdx,
/* Generated */                                    int    endIdx,
/* Generated */                                    double       inOpen[],
/* Generated */                                    double       inHigh[],
/* Generated */                                    double       inLow[],
/* Generated */                                    double       inClose[],
/* Generated */                                    MInteger     outBegIdx,
/* Generated */                                    MInteger     outNBElement,
/* Generated */                                    int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_LIB_API TA_RetCode TA_CDLIDENTICAL3CROWS( int    startIdx,
/* Generated */                                              int    endIdx,
/* Generated */                                                         const double inOpen[],
/* Generated */                                                         const double inHigh[],
/* Generated */                                                         const double inLow[],
/* Generated */                                                         const double inClose[],
/* Generated */                                                         int          *outBegIdx,
/* Generated */                                                         int          *outNBElement,
/* Generated */                                                         int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    ARRAY_LOCAL(ShadowVeryShortPeriodTotal,3);
	ARRAY_LOCAL(EqualPeriodTotal,3);
    int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, EqualTrailingIdx, lookbackTotal;

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */ 
/* Generated */    #if !defined(_JAVA)
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA)*/
/* Generated */    #if !defined(_JAVA)
/* Generated */    if( !outInteger )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = LOOKBACK_CALL(CDLIDENTICAL3CROWS)();

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
      return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   ShadowVeryShortPeriodTotal[2] = 0;
   ShadowVeryShortPeriodTotal[1] = 0;
   ShadowVeryShortPeriodTotal[0] = 0;
   ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(ShadowVeryShort);
   EqualPeriodTotal[2] = 0;
   EqualPeriodTotal[1] = 0;
   EqualPeriodTotal[0] = 0;
   EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(Equal);
   
   i = ShadowVeryShortTrailingIdx;
   while( i < startIdx ) {
        ShadowVeryShortPeriodTotal[2] += TA_CANDLERANGE( ShadowVeryShort, i-2 );
        ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( ShadowVeryShort, i-1 );
        ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( ShadowVeryShort, i );
        i++;
   }
   i = EqualTrailingIdx;
   while( i < startIdx ) {
        EqualPeriodTotal[2] += TA_CANDLERANGE( Equal, i-2 );
        EqualPeriodTotal[1] += TA_CANDLERANGE( Equal, i-1 );
        i++;
   }
   i = startIdx;

#ifdef TA_LIB_PRO
      /* Section for code distributed with TA-Lib Pro only. */
#endif

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - three consecutive and declining black candlesticks
    * - each candle must have no or very short lower shadow
    * - each candle after the first must open at or very close to the prior candle's close
    * The meaning of "very short" is specified with TA_SetCandleSettings;
    * the meaning of "very close" is specified with TA_SetCandleSettings (Equal);
    * outInteger is negative (-1 to -100): identical three crows is always bearish; 
    * the user should consider that identical 3 crows is significant when it appears after a mature advance or at high levels, 
    * while this function does not consider it
    */
   outIdx = 0;
   do
   {
#ifdef TA_LIB_PRO
      /* Section for code distributed with TA-Lib Pro only. */
#else
        if( TA_CANDLECOLOR(i-2) == -1 &&                                    // 1st black
                                                                            // very short lower shadow
            TA_LOWERSHADOW(i-2) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[2], i-2 ) &&     
            TA_CANDLECOLOR(i-1) == -1 &&                                    // 2nd black
                                                                            // very short lower shadow
            TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&     
            TA_CANDLECOLOR(i) == -1 &&                                      // 3rd black
                                                                            // very short lower shadow
            TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&         
            inClose[i-2] > inClose[i-1] &&                                  // three declining
            inClose[i-1] > inClose[i] &&
                                                                            // 2nd black opens very close to 1st close
            inOpen[i-1] <= inClose[i-2] + TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[2], i-2 ) && 
            inOpen[i-1] >= inClose[i-2] - TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[2], i-2 ) &&
                                                                            // 3rd black opens very close to 2nd close 
            inOpen[i] <= inClose[i-1] + TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[1], i-1 ) &&   
            inOpen[i] >= inClose[i-1] - TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[1], i-1 )
          )
            outInteger[outIdx++] = -100;
        else
            outInteger[outIdx++] = 0;
#endif
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        for (totIdx = 2; totIdx >= 0; --totIdx)
            ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( ShadowVeryShort, i-totIdx ) 
                                                - TA_CANDLERANGE( ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
        for (totIdx = 2; totIdx >= 1; --totIdx)
            EqualPeriodTotal[totIdx] += TA_CANDLERANGE( Equal, i-totIdx ) 
                                      - TA_CANDLERANGE( Equal, EqualTrailingIdx-totIdx );
        i++; 
        ShadowVeryShortTrailingIdx++;
        EqualTrailingIdx++;
   } while( i <= endIdx );

   /* All done. Indicate the output limits and return. */
   VALUE_HANDLE_DEREF(outNBElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

   return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #undef  TA_LIB_PRO
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED ) && defined( USE_SUBARRAY )
/* Generated */ enum class Core::RetCode Core::CdlIdentical3Crows( int    startIdx,
/* Generated */                                                    int    endIdx,
/* Generated */                                                    SubArray<float>^ inOpen,
/* Generated */                                                    SubArray<float>^ inHigh,
/* Generated */                                                    SubArray<float>^ inLow,
/* Generated */                                                    SubArray<float>^ inClose,
/* Generated */                                                    [Out]int%    outBegIdx,
/* Generated */                                                    [Out]int%    outNBElement,
/* Generated */                                                    SubArray<int>^  outInteger )
/* Generated */ #elif defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::CdlIdentical3Crows( int    startIdx,
/* Generated */                                                    int    endIdx,
/* Generated */                                                    cli::array<float>^ inOpen,
/* Generated */                                                    cli::array<float>^ inHigh,
/* Generated */                                                    cli::array<float>^ inLow,
/* Generated */                                                    cli::array<float>^ inClose,
/* Generated */                                                    [Out]int%    outBegIdx,
/* Generated */                                                    [Out]int%    outNBElement,
/* Generated */                                                    cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode cdlIdentical3Crows( int    startIdx,
/* Generated */                                    int    endIdx,
/* Generated */                                    float        inOpen[],
/* Generated */                                    float        inHigh[],
/* Generated */                                    float        inLow[],
/* Generated */                                    float        inClose[],
/* Generated */                                    MInteger     outBegIdx,
/* Generated */                                    MInteger     outNBElement,
/* Generated */                                    int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLIDENTICAL3CROWS( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     const float  inOpen[],
/* Generated */                                     const float  inHigh[],
/* Generated */                                     const float  inLow[],
/* Generated */                                     const float  inClose[],
/* Generated */                                     int          *outBegIdx,
/* Generated */                                     int          *outNBElement,
/* Generated */                                     int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     ARRAY_LOCAL(ShadowVeryShortPeriodTotal,3);
/* Generated */ 	ARRAY_LOCAL(EqualPeriodTotal,3);
/* Generated */     int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, EqualTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */     #if !defined(_JAVA)
/* Generated */     if( !outInteger )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    lookbackTotal = LOOKBACK_CALL(CDLIDENTICAL3CROWS)();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
/* Generated */       return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */    }
/* Generated */    ShadowVeryShortPeriodTotal[2] = 0;
/* Generated */    ShadowVeryShortPeriodTotal[1] = 0;
/* Generated */    ShadowVeryShortPeriodTotal[0] = 0;
/* Generated */    ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(ShadowVeryShort);
/* Generated */    EqualPeriodTotal[2] = 0;
/* Generated */    EqualPeriodTotal[1] = 0;
/* Generated */    EqualPeriodTotal[0] = 0;
/* Generated */    EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(Equal);
/* Generated */    i = ShadowVeryShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         ShadowVeryShortPeriodTotal[2] += TA_CANDLERANGE( ShadowVeryShort, i-2 );
/* Generated */         ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( ShadowVeryShort, i-1 );
/* Generated */         ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( ShadowVeryShort, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = EqualTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         EqualPeriodTotal[2] += TA_CANDLERANGE( Equal, i-2 );
/* Generated */         EqualPeriodTotal[1] += TA_CANDLERANGE( Equal, i-1 );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */ #ifdef TA_LIB_PRO
/* Generated */ #endif
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */ #ifdef TA_LIB_PRO
/* Generated */ #else
/* Generated */         if( TA_CANDLECOLOR(i-2) == -1 &&                                    // 1st black
/* Generated */                                                                             // very short lower shadow
/* Generated */             TA_LOWERSHADOW(i-2) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[2], i-2 ) &&     
/* Generated */             TA_CANDLECOLOR(i-1) == -1 &&                                    // 2nd black
/* Generated */                                                                             // very short lower shadow
/* Generated */             TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&     
/* Generated */             TA_CANDLECOLOR(i) == -1 &&                                      // 3rd black
/* Generated */                                                                             // very short lower shadow
/* Generated */             TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&         
/* Generated */             inClose[i-2] > inClose[i-1] &&                                  // three declining
/* Generated */             inClose[i-1] > inClose[i] &&
/* Generated */                                                                             // 2nd black opens very close to 1st close
/* Generated */             inOpen[i-1] <= inClose[i-2] + TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[2], i-2 ) && 
/* Generated */             inOpen[i-1] >= inClose[i-2] - TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[2], i-2 ) &&
/* Generated */                                                                             // 3rd black opens very close to 2nd close 
/* Generated */             inOpen[i] <= inClose[i-1] + TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[1], i-1 ) &&   
/* Generated */             inOpen[i] >= inClose[i-1] - TA_CANDLEAVERAGE( Equal, EqualPeriodTotal[1], i-1 )
/* Generated */           )
/* Generated */             outInteger[outIdx++] = -100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */ #endif
/* Generated */         for (totIdx = 2; totIdx >= 0; --totIdx)
/* Generated */             ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( ShadowVeryShort, i-totIdx ) 
/* Generated */                                                 - TA_CANDLERANGE( ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
/* Generated */         for (totIdx = 2; totIdx >= 1; --totIdx)
/* Generated */             EqualPeriodTotal[totIdx] += TA_CANDLERANGE( Equal, i-totIdx ) 
/* Generated */                                       - TA_CANDLERANGE( Equal, EqualTrailingIdx-totIdx );
/* Generated */         i++; 
/* Generated */         ShadowVeryShortTrailingIdx++;
/* Generated */         EqualTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */    VALUE_HANDLE_DEREF(outNBElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return ENUM_VALUE(RetCode,TA_SUCCESS,Success);
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }}} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

{
   /* insert local variable here */

/**** START GENCODE SECTION 6 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 6 - DO NOT DELETE THIS LINE ****/

   /* insert state init code here. */

   _state = NULL;
   return 0;
}

/**** START GENCODE SECTION 7 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 7 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 8 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 8 - DO NOT DELETE THIS LINE ****/

   /* insert state based TA dunc code here. */

   return 0;
}

/**** START GENCODE SECTION 9 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 9 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 10 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 10 - DO NOT DELETE THIS LINE ****/

   /* insert state free code here. */   
   return 0;
}

/**** START GENCODE SECTION 11 - DO NOT DELETE THIS LINE ****/
%%%GENCODE%%%
/**** END GENCODE SECTION 11 - DO NOT DELETE THIS LINE ****/

