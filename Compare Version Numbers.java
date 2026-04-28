class Solution {
    public int compareVersion(String version1, String version2) {
        // Split by the dot literal (requires escape \\. in regex)
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        
        int maxLength = Math.max(v1.length, v2.length);
        
        for (int i = 0; i < maxLength; i++) {
            // Use 0 if we've run out of revisions for one version
            int num1 = i < v1.length ? Integer.parseInt(v1[i]) : 0;
            int num2 = i < v2.length ? Integer.parseInt(v2[i]) : 0;
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        
        return 0;
    }
}
