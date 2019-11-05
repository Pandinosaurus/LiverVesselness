#ifndef bench_evaluation_h
#define bench_evaluation_h

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionConstIterator.h"
#include <iostream>

// map to store values
using VoxelsMap = std::map<std::string,std::vector<long> >;
using MetricsMap = std::map<std::string,std::vector<double> >;

template<typename TImageType, typename TGroundTruthImageType, typename TMaskImageType>
class Eval{
 public:
  Eval(const typename TImageType::Pointer segmentation, const typename TGroundTruthImageType::Pointer gt, const typename TMaskImageType::Pointer mask);

  long TP(){return m_truePositive;}
  long TN(){return m_trueNegative;}
  long FP(){return m_falsePositive;}
  long FN(){return m_falseNegative;}


  double sensitivity();
  double specificity();
  double precision();
  double accuracy();
  double dice();
  long double matthewsCorrelation();

  static void roc(VoxelsMap &vMap);
    
  void print();
 private:
  void countMatchesBinary(const typename TImageType::Pointer img, const typename TGroundTruthImageType::Pointer gt, const typename TMaskImageType::Pointer mask);
  
  long m_truePositive;
  long m_trueNegative;
  long m_falsePositive;
  long m_falseNegative;
};

#include "bench_evaluation.hxx"

#endif // bench_evaluation_h
