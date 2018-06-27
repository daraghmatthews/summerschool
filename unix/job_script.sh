#!/bin/bash
#SBATCH -J daraghs_job
#SBATCH -o %J.out
#SBATCH -e %J.err
#SBATCH -n 24
#SBATCH -p small
#SBATCH -t 5
#SBATCH --reservation=summer_school
aprun -n 24 ./prog


