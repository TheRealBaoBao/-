from typing import List
from collections import Counter
import bisect

class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        """
        Initialize the TopVotedCandidate with voting records.

        Args:
            persons: List of person IDs who received votes at corresponding times
            times: List of timestamps when votes were cast (in ascending order)
        """
        # Counter to track vote counts for each person
        vote_counter = Counter()

        # Store the times array for binary search in queries
        self.times = times

        # List to store the leading candidate at each timestamp
        self.leading_candidates = []

        # Track the current leader
        current_leader = 0

        # Process each vote in chronological order
        for person in persons:
            # Increment vote count for this person
            vote_counter[person] += 1

            # Update leader if current person has equal or more votes
            # (ties go to the most recent vote)
            if vote_counter[current_leader] <= vote_counter[person]:
                current_leader = person

            # Record the leader after this vote
            self.leading_candidates.append(current_leader)

    def q(self, t: int) -> int:
        """
        Query the leading candidate at a given time.

        Args:
            t: The timestamp to query

        Returns:
            The ID of the person leading at time t
        """
        # Find the rightmost vote that occurred at or before time t
        # bisect_right returns insertion point, so subtract 1 to get the index
        index = bisect.bisect_right(self.times, t) - 1

        # Return the leader at that point in time
        return self.leading_candidates[index]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
